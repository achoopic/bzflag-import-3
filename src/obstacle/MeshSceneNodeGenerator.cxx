/* bzflag
 * Copyright (c) 1993 - 2004 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <math.h>
#include "vectors.h"
#include "MeshSceneNodeGenerator.h"
#include "MeshObstacle.h"
#include "MeshFace.h"
#include "bzfgl.h"
#include "MeshPolySceneNode.h"
#include "MeshFragSceneNode.h"
#include "DynamicColor.h"
#include "TextureManager.h"
#include "OpenGLMaterial.h"
#include "StateDatabase.h"
#include "BZDBCache.h"


//
// MeshSceneNodeGenerator
//

MeshSceneNodeGenerator::MeshSceneNodeGenerator(const MeshObstacle* _mesh)
{
  mesh = _mesh;
  currentNode = 0;
  setupFacesAndFrags();
  return;
}


MeshSceneNodeGenerator::~MeshSceneNodeGenerator()
{
  // do nothing
  return;
}


static bool invisibleMaterial(const BzMaterial* mat)
{
  const DynamicColor* dyncol = DYNCOLORMGR.getColor(mat->getDynamicColor());
  if ((mat->getDiffuse()[3] == 0.0f) && (dyncol == NULL) &&
      !((mat->getTextureCount() > 0) && !mat->getUseColorOnTexture(0))) {
    // face is invisible
    return true;
  }
  return false;
}


static bool translucentMaterial(const BzMaterial* mat)
{
  // translucent texture?
  TextureManager &tm = TextureManager::instance();
  int faceTexture = -1;
  if ((mat->getTextureCount() > 0) &&(mat->getTexture(0).size() > 0)) {
    faceTexture = tm.getTextureID(mat->getTexture(0).c_str());
    if (faceTexture >= 0) {
      const ImageInfo& imageInfo = tm.getInfo(faceTexture);
      if (imageInfo.alpha && mat->getUseTextureAlpha(0)) {
        return true;
      }
    }
  }

  // translucent color?
  if (mat->getDiffuse()[3] != 1.0f) {
    if (((faceTexture >= 0) && mat->getUseColorOnTexture(0)) ||
        (faceTexture < 0)) {
      // modulate with the color if asked to, or
      // if the specified texture was not available
      return true;
    }
  }

  // translucent Dynamic Color?
  const DynamicColor* dyncol = DYNCOLORMGR.getColor(mat->getDynamicColor());
  if ((dyncol != NULL) && dyncol->canHaveAlpha()) {
    return true;
  }

  return false;
}


static bool groundClippedFace(const MeshFace* face)
{
  const float* plane = face->getPlane();
  if (plane[2] < -0.9f) {
    // plane is facing downwards
    float mins[3], maxs[3];
    face->getExtents(mins, maxs);
    if (maxs[2] < 0.001) {
      // plane is on or below the ground, ditch it
      return true;
    }
  }
  return false;
}


static int sortByMaterial(const void* a, const void *b)
{
  const MeshFace* faceA = *((const MeshFace**)a);
  const MeshFace* faceB = *((const MeshFace**)b);
  
  if (faceA->getMaterial() > faceB->getMaterial()) {
    return +1;
  } else {
    return -1;
  }
}

void MeshSceneNodeGenerator::setupFacesAndFrags()
{
  const int faceCount = mesh->getFaceCount();

  // just using regular MeshFaces?
  const bool useMeshFrags = !BZDB.isTrue("noMeshFragments");
  if (!(mesh->useFragments() && useMeshFrags && BZDBCache::zbuffer)) {
    for (int i = 0; i < faceCount; i++) {
      MeshNode mn;
      mn.isFace = true;
      mn.faces.push_back(mesh->getFace(i));
      nodes.push_back(mn);
    }
    
    return;
  } 
  

  // build up a list of faces and fragments
  const MeshFace** sortList = new const MeshFace*[faceCount];

  // clip ground faces, and then sort the face list by material
  int count = 0;
  for (int i = 0; i < faceCount; i++) {
    const MeshFace* face = mesh->getFace(i);
    if (!groundClippedFace(face)) {
      sortList[count] = face;
      count++;
    }
  }
  qsort(sortList, count, sizeof(MeshFace*), sortByMaterial);
  
  // make the faces and fragments
  int first = 0;
  while (first < count) {
    const MeshFace* firstFace = sortList[first];
    const BzMaterial* firstMat = firstFace->getMaterial();
    
    // translucent faces are drawn individually
    if (translucentMaterial(firstMat)) {
      MeshNode mn;
      mn.isFace = true;
      mn.faces.push_back(firstFace);
      nodes.push_back(mn);
      first++;
      continue;
    }

    // collate similar materials    
    int last = first + 1;
    while (last < count) {
      const MeshFace* lastFace = sortList[last];
      const BzMaterial* lastMat = lastFace->getMaterial();
      if (lastMat != firstMat) {
        break;
      }
      last++;
    }

    // make a face for singles, and a fragment otherwise
    if ((last - first) == 1) {
      MeshNode mn;
      mn.isFace = true;
      mn.faces.push_back(firstFace);
      nodes.push_back(mn);
    } else {
      MeshNode mn;
      mn.isFace = false;
      for (int i = first; i < last; i++) {
        mn.faces.push_back(sortList[i]);
      }
      nodes.push_back(mn);
    }
    
    first = last;
  }

  delete[] sortList;

  return;
}


WallSceneNode* MeshSceneNodeGenerator::getNextNode(bool /*lod*/)
{
  const MeshNode* mn;
  const MeshFace* face;
  const BzMaterial* mat;

  // remove any faces or frags that will not be displayed
  // also, return NULL if we are at the end of the face list
  while (true) {

    if (currentNode >= (int)nodes.size()) {
      return NULL;
    }
    
    mn = &nodes[currentNode];
    if (mn->isFace) {
      face = mn->faces[0];
      mat = face->getMaterial();
    } else {
      face = NULL;
      mat = mn->faces[0]->getMaterial();
    }
    
    if (invisibleMaterial(mat)) {
      currentNode++;
      continue;
    }

    if (mn->isFace && groundClippedFace(face)) {
      currentNode++;
      continue;
    }
    
    break; // break the loop if we haven't used 'continue'
  }

  WallSceneNode* node;
  if (mn->isFace) {
    node = getMeshPolySceneNode(face);
  } else {
    const MeshFace** faces = new const MeshFace*[mn->faces.size()];
    for (int i = 0; i < (int)mn->faces.size(); i++) {
      faces[i] = mn->faces[i];
    }
    // the MeshFragSceneNode will delete the faces
    node = new MeshFragSceneNode(mn->faces.size(), faces);
  }

  setupNodeMaterial(node, mat);

  currentNode++;

  return node;
}


MeshPolySceneNode* MeshSceneNodeGenerator::getMeshPolySceneNode(const MeshFace* face)
{
  int i;
  
  // vertices
  const int vertexCount = face->getVertexCount();
  GLfloat3Array vertices(vertexCount);
  for (i = 0; i < vertexCount; i++) {
    memcpy (vertices[i], face->getVertex(i), sizeof(float[3]));
  }

  // normals
  int normalCount = 0;
  if (face->useNormals()) {
    normalCount = vertexCount;
  }
  GLfloat3Array normals(normalCount);
  for (i = 0; i < normalCount; i++) {
    memcpy (normals[i], face->getNormal(i), sizeof(float[3]));
  }

  // texcoords
  GLfloat2Array texcoords(vertexCount);
  if (face->useTexcoords()) {
    for (i = 0; i < vertexCount; i++) {
      memcpy (texcoords[i], face->getTexcoord(i), sizeof(float[2]));
    }
  } else {
    makeTexcoords (face->getPlane(), vertices, texcoords);
  }

  MeshPolySceneNode* node =
    new MeshPolySceneNode(face->getPlane(), vertices, normals, texcoords);
    
  return node;
}


void MeshSceneNodeGenerator::setupNodeMaterial(WallSceneNode* node,
                                               const BzMaterial* mat)
{
  TextureManager &tm = TextureManager::instance();
  OpenGLMaterial glMaterial(mat->getSpecular(), mat->getEmission(), mat->getShininess());

  int userTexture = (mat->getTextureCount() > 0);
  int faceTexture = -1;
  bool gotSpecifiedTexture = false;
  if (userTexture) {
    if (mat->getTexture(0).size() > 0) {
      faceTexture = tm.getTextureID(mat->getTexture(0).c_str());
    }
    if (faceTexture >= 0) {
      gotSpecifiedTexture = true;
    } else {
      faceTexture = tm.getTextureID("mesh", false /* no failure reports */);
    }
  }

  // NOTE: the diffuse color is used, and not the ambient color
  //       could use the ambient color for non-lighted,and diffuse
  //       for lighted
  const DynamicColor* dyncol = DYNCOLORMGR.getColor(mat->getDynamicColor());
  const GLfloat* dc = NULL;
  if (dyncol != NULL) {
    dc = dyncol->getColor();
  }
  node->setDynamicColor(dc);
  node->setColor(mat->getDiffuse()); // redundant, see below
  node->setModulateColor(mat->getDiffuse());
  node->setLightedColor(mat->getDiffuse());
  node->setLightedModulateColor(mat->getDiffuse());
  node->setMaterial(glMaterial);
  node->setTexture(faceTexture);
  if ((userTexture && mat->getUseColorOnTexture(0)) ||
      !gotSpecifiedTexture) {
    // modulate with the color if asked to, or
    // if the specified texture was not available
    node->setUseColorTexture(false);
  } else {
    node->setUseColorTexture(true);
  }
  node->setTextureMatrix(mat->getTextureMatrix(0));

  // deal with the blending setting for textures
  bool alpha = false;
  if ((faceTexture >= 0) && (userTexture && mat->getUseTextureAlpha(0))) {
    const ImageInfo& imageInfo = tm.getInfo(faceTexture);
    alpha = imageInfo.alpha;
  }
  node->setBlending(alpha);
  node->setSphereMap(mat->getUseSphereMap(0));

  // the current color can also affect the blending.
  // if blending is disabled then the alpha value from
  // one of these colors is used to set the stipple value.
  // we'll just set it to the middle value.
  if (dyncol) {
    const float color[4] = { 1.0f, 1.0f, 1.0f, 0.5f }; // alpha value != 1.0f
    if (dyncol->canHaveAlpha()) {
      node->setColor(color); // trigger transparency check
      node->setModulateColor(color);
      node->setLightedColor(color);
      node->setLightedModulateColor(color);
    }
  }
}


bool MeshSceneNodeGenerator::makeTexcoords(const float* plane,
                                           const GLfloat3Array& vertices,
                                           GLfloat2Array& texcoords)
{
  float x[3], y[3];

  vec3sub (x, vertices[1], vertices[0]);
  vec3cross (y, plane, x);

  float len = vec3dot(x, x);
  if (len > 0.0f) {
    len = 1.0f / sqrtf(len);
    x[0] = x[0] * len;
    x[1] = x[1] * len;
    x[2] = x[2] * len;
  } else {
    return false;
  }

  len = vec3dot(y, y);
  if (len > 0.0f) {
    len = 1.0f / sqrtf(len);
    y[0] = y[0] * len;
    y[1] = y[1] * len;
    y[2] = y[2] * len;
  } else {
    return false;
  }

  const float uvScale = 8.0f;

  texcoords[0][0] = 0.0f;
  texcoords[0][1] = 0.0f;
  const int count = vertices.getSize();
  for (int i = 1; i < count; i++) {
    float delta[3];
    vec3sub (delta, vertices[i], vertices[0]);
    texcoords[i][0] = vec3dot(delta, x) / uvScale;
    texcoords[i][1] = vec3dot(delta, y) / uvScale;
  }
  
  return true;
}


// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
