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

/* Teleporter:
 *	Encapsulates a box in the game environment.
 */

#ifndef	BZF_TELEPORTER_H
#define	BZF_TELEPORTER_H

#include "common.h"
#include <string>
#include "Obstacle.h"
#include "MeshFace.h"

class Teleporter : public Obstacle {
  public:
			Teleporter(const float* pos, float rotation,
				float width, float breadth, float height,
				float borderSize = 1.0f, bool horizontal = false, bool drive = false, bool shoot = false);
			~Teleporter();

    const char*		getType() const;
    static const char*	getClassName(); // const
    void		getExtents(float* mins, float* maxs) const;

    float		getBorder() const;
    bool		isHorizontal() const;
    bool		isValid() const;

    float		intersect(const Ray&) const;
    void		getNormal(const float* p, float* n) const;

    bool		inCylinder(const float* p, float radius, float height) const;
    bool		inBox(const float* p, float angle,
			      float halfWidth, float halfBreadth, float height) const;
    bool		inMovingBox(const float* oldP, float oldAngle,
				    const float *newP, float newAngle,
				    float halfWidth, float halfBreadth, float height) const;
    bool		isCrossing(const float* p, float angle,
				   float halfWidth, float halfBreadth, float height,
				   float* plane) const;

    bool		getHitNormal(
				const float* pos1, float azimuth1,
				const float* pos2, float azimuth2,
				float halfWidth, float halfBreadth,
				float height,
				float* normal) const;

    float		isTeleported(const Ray&, int& face) const;
    float		getProximity(const float* p, float radius) const;
    bool		hasCrossed(const float* p1, const float* p2,
							int& face) const;
    void		getPointWRT(const Teleporter& t2, int face1, int face2,
				const float* pIn, const float* dIn, float aIn,
				float* pOut, float* dOut, float* aOut) const;

    void makeLinks();
    const MeshFace* getBackLink() const;
    const MeshFace* getFrontLink() const;

    std::string		userTextures[1];
  private:
    float		border;
	bool		horizontal;
    static const char*	typeName;

    MeshFace* backLink;
    MeshFace* frontLink;
    float fvertices[4][3]; // front vertices
    float bvertices[4][3]; // back vertices
    float texcoords[4][2]; // shared texture coordinates
};

const int randomTeleporter = (unsigned short)(-1);

//
// Teleporter
//

inline float Teleporter::getBorder() const
{
  return border;
}

inline bool Teleporter::isHorizontal() const
{
  return horizontal;
}

inline const MeshFace* Teleporter::getBackLink() const
{
  return backLink;
}

inline const MeshFace* Teleporter::getFrontLink() const
{
  return frontLink;
}


#endif // BZF_TELEPORTER_H

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

