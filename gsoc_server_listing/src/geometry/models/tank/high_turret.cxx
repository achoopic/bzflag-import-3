/* bzflag
 * Copyright (c) 1993 - 2008 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
#include "TankGeometryMgr.h"
using namespace TankGeometryUtils;

int TankGeometryUtils::buildHighTurret ( void )
{
  int count = 0;
  if (buildGeoFromObj("/std/turret.obj",count))
    return count;

  int tris = 0;

  glShadeModel(GL_FLAT);

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(0.005904f, 0.999963f, 0.006290f);
    doTexCoord2f(0.999f, 0.075f);
    doVertex3f(-0.946f, 0.762f, 1.970f);
    doTexCoord2f(1.060f, 0.015f);
    doVertex3f(-0.964f, 0.765f, 1.510f);
    doTexCoord2f(1.080f, 0.169f);
    doVertex3f(-1.370f, 0.764f, 2.050f);
    doNormal3f(-0.002024f, 0.999998f, 0.000330f);
    doTexCoord2f(1.160f, 0.119f);
    doVertex3f(-1.450f, 0.764f, 1.560f);
  glEnd();
  tris += 2;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-0.002288f, -0.999997f, 0.000374f);
    doTexCoord2f(0.866f, 0.402f);
    doVertex3f(-1.370f, -0.765f, 2.050f);
    doTexCoord2f(0.822f, 0.484f);
    doVertex3f(-1.450f, -0.765f, 1.560f);
    doTexCoord2f(0.766f, 0.326f);
    doVertex3f(-0.946f, -0.766f, 1.970f);
    doNormal3f(-0.000223f, -0.999998f, -0.002165f);
    doTexCoord2f(0.711f, 0.394f);
    doVertex3f(-0.964f, -0.765f, 1.510f);
  glEnd();
  tris += 2;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-1.000000f, 0.000000f, 0.000000f);
    doTexCoord2f(0.996f, -0.132f);
    doVertex3f(-0.456f, 1.080f, 1.040f);
    doTexCoord2f(0.559f, 0.339f);
    doVertex3f(-0.456f, -1.060f, 1.040f);
    doTexCoord2f(0.973f, -0.107f);
    doVertex3f(-0.456f, 1.080f, 1.310f);
    doTexCoord2f(0.583f, 0.312f);
    doVertex3f(-0.456f, -1.060f, 1.310f);
    doNormal3f(-0.366332f, 0.000000f, -0.930484f);
    doTexCoord2f(1.060f, 0.015f);
    doVertex3f(-0.964f, 0.765f, 1.510f);
    doTexCoord2f(0.711f, 0.394f);
    doVertex3f(-0.964f, -0.765f, 1.510f);
  glEnd();
  tris += 4;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(1.000000f, 0.000000f, 0.000000f);
    doTexCoord2f(0.107f, -0.009f);
    doVertex3f(1.480f, -0.516f, 1.040f);
    doTexCoord2f(0.617f, -0.559f);
    doVertex3f(1.480f, 0.516f, 1.040f);
    doTexCoord2f(0.143f, -0.049f);
    doVertex3f(1.480f, -0.516f, 1.310f);
    doTexCoord2f(0.581f, -0.519f);
    doVertex3f(1.480f, 0.516f, 1.310f);
    doNormal3f(0.621395f, 0.000000f, -0.783498f);
    doTexCoord2f(0.126f, -0.155f);
    doVertex3f(1.770f, -0.434f, 1.540f);
    doTexCoord2f(0.473f, -0.529f);
    doVertex3f(1.770f, 0.434f, 1.540f);
    doNormal3f(0.796162f, 0.000000f, 0.605083f);
    doTexCoord2f(0.224f, -0.178f);
    doVertex3f(1.580f, -0.434f, 1.790f);
    doTexCoord2f(0.457f, -0.429f);
    doVertex3f(1.580f, 0.435f, 1.790f);
    doNormal3f(0.310402f, 0.000000f, 0.950605f);
    doTexCoord2f(0.331f, -0.083f);
    doVertex3f(1.090f, -0.697f, 1.950f);
    doTexCoord2f(0.560f, -0.329f);
    doVertex3f(1.090f, 0.697f, 1.950f);
    doNormal3f(-0.009186f, 0.000000f, 0.999958f);
    doTexCoord2f(0.546f, 0.156f);
    doVertex3f(0.001f, -1.110f, 1.940f);
    doTexCoord2f(0.812f, -0.134f);
    doVertex3f(0.007f, 1.110f, 1.940f);
    doNormal3f(-0.048902f, 0.000130f, 0.998804f);
    doTexCoord2f(0.678f, 0.276f);
    doVertex3f(-0.611f, -0.984f, 1.910f);
    doTexCoord2f(0.944f, -0.010f);
    doVertex3f(-0.611f, 1.010f, 1.910f);
    doNormal3f(0.176299f, 0.000000f, 0.984337f);
    doTexCoord2f(0.766f, 0.326f);
    doVertex3f(-0.946f, -0.766f, 1.970f);
    doTexCoord2f(0.999f, 0.075f);
    doVertex3f(-0.946f, 0.762f, 1.970f);
  glEnd();
  tris += 14;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-1.000000f, 0.000000f, 0.000000f);
    doTexCoord2f(0.890f, 0.022f);
    doVertex3f(-0.548f, 0.599f, 2.050f);
    doTexCoord2f(0.909f, 0.002f);
    doVertex3f(-0.548f, 0.599f, 1.920f);
    doTexCoord2f(0.706f, 0.220f);
    doVertex3f(-0.548f, -0.599f, 2.050f);
    doTexCoord2f(0.687f, 0.241f);
    doVertex3f(-0.548f, -0.599f, 1.920f);
  glEnd();
  tris += 2;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(0.000000f, 0.000000f, 1.000000f);
    doTexCoord2f(0.606f, 0.158f);
    doVertex3f(-0.156f, -0.796f, 2.050f);
    doTexCoord2f(0.552f, 0.102f);
    doVertex3f(0.108f, -0.757f, 2.050f);
    doTexCoord2f(0.669f, 0.204f);
    doVertex3f(-0.418f, -0.704f, 2.050f);
    doTexCoord2f(0.532f, 0.067f);
    doVertex3f(0.238f, -0.644f, 2.050f);
    doTexCoord2f(0.706f, 0.220f);
    doVertex3f(-0.548f, -0.599f, 2.050f);
    doTexCoord2f(0.529f, 0.038f);
    doVertex3f(0.313f, -0.503f, 2.050f);
    doTexCoord2f(0.890f, 0.022f);
    doVertex3f(-0.548f, 0.599f, 2.050f);
    doTexCoord2f(0.695f, -0.140f);
    doVertex3f(0.313f, 0.503f, 2.050f);
    doTexCoord2f(0.871f, -0.013f);
    doVertex3f(-0.418f, 0.704f, 2.050f);
    doTexCoord2f(0.725f, -0.139f);
    doVertex3f(0.238f, 0.644f, 2.050f);
    doTexCoord2f(0.820f, -0.072f);
    doVertex3f(-0.156f, 0.796f, 2.050f);
    doTexCoord2f(0.760f, -0.122f);
    doVertex3f(0.108f, 0.757f, 2.050f);
  glEnd();
  tris += 10;

  glShadeModel(GL_SMOOTH);
  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-0.542880f, -0.839586f, 0.019418f);
    doTexCoord2f(0.766f, 0.326f);
    doVertex3f(-0.946f, -0.766f, 1.970f);
    doTexCoord2f(0.711f, 0.394f);
    doVertex3f(-0.964f, -0.765f, 1.510f);
    doNormal3f(-0.361706f, -0.931967f, 0.024608f);
    doTexCoord2f(0.678f, 0.276f);
    doVertex3f(-0.611f, -0.984f, 1.910f);
    doNormal3f(-0.508623f, -0.860699f, -0.022373f);
    doTexCoord2f(0.583f, 0.312f);
    doVertex3f(-0.456f, -1.060f, 1.310f);
    doNormal3f(0.138220f, -0.990318f, -0.012863f);
    doTexCoord2f(0.546f, 0.156f);
    doVertex3f(0.001f, -1.110f, 1.940f);
    doNormal3f(-0.085240f, -0.996212f, -0.017176f);
    doTexCoord2f(0.482f, 0.218f);
    doVertex3f(0.014f, -1.100f, 1.300f);
    doNormal3f(0.411649f, -0.910469f, -0.039891f);
    doTexCoord2f(0.331f, -0.083f);
    doVertex3f(1.090f, -0.697f, 1.950f);
    doNormal3f(0.363757f, -0.931155f, -0.025121f);
    doTexCoord2f(0.279f, 0.051f);
    doVertex3f(0.912f, -0.749f, 1.300f);
    doNormal3f(0.276338f, -0.955239f, 0.105616f);
    doTexCoord2f(0.224f, -0.178f);
    doVertex3f(1.580f, -0.434f, 1.790f);
    doNormal3f(0.377141f, -0.922775f, 0.079070f);
    doTexCoord2f(0.143f, -0.049f);
    doVertex3f(1.480f, -0.516f, 1.310f);
    doNormal3f(0.172242f, -0.976318f, 0.130904f);
    doTexCoord2f(0.126f, -0.155f);
    doVertex3f(1.770f, -0.434f, 1.540f);
  glEnd();
  tris += 9;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(0.174171f, 0.976300f, 0.128465f);
    doTexCoord2f(0.473f, -0.529f);
    doVertex3f(1.770f, 0.434f, 1.540f);
    doTexCoord2f(0.581f, -0.519f);
    doVertex3f(1.480f, 0.516f, 1.310f);
    doNormal3f(0.418428f, 0.908177f, 0.011546f);
    doTexCoord2f(0.457f, -0.429f);
    doVertex3f(1.580f, 0.435f, 1.790f);
    doNormal3f(0.377227f, 0.922902f, 0.077151f);
    doTexCoord2f(0.690f, -0.391f);
    doVertex3f(0.912f, 0.749f, 1.300f);
    doNormal3f(0.360127f, 0.932727f, -0.018136f);
    doTexCoord2f(0.560f, -0.329f);
    doVertex3f(1.090f, 0.697f, 1.950f);
    doNormal3f(0.363757f, 0.931155f, -0.025121f);
    doTexCoord2f(0.872f, -0.201f);
    doVertex3f(0.014f, 1.100f, 1.300f);
    doNormal3f(-0.103074f, 0.994267f, 0.028456f);
    doTexCoord2f(0.812f, -0.134f);
    doVertex3f(0.007f, 1.110f, 1.940f);
    doNormal3f(-0.042895f, 0.998951f, -0.016023f);
    doTexCoord2f(0.973f, -0.107f);
    doVertex3f(-0.456f, 1.080f, 1.310f);
    doNormal3f(-0.565415f, 0.824783f, -0.006201f);
    doTexCoord2f(0.944f, -0.010f);
    doVertex3f(-0.611f, 1.010f, 1.910f);
    doNormal3f(-0.538099f, 0.841894f, -0.040788f);
    doTexCoord2f(1.060f, 0.015f);
    doVertex3f(-0.964f, 0.765f, 1.510f);
    doNormal3f(-0.591467f, 0.805829f, 0.028400f);
    doTexCoord2f(0.999f, 0.075f);
    doVertex3f(-0.946f, 0.762f, 1.970f);
  glEnd();
  tris += 9;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-0.928088f, 0.340137f, 0.151525f);
    doTexCoord2f(1.080f, 0.169f);
    doVertex3f(-1.370f, 0.764f, 2.050f);
    doTexCoord2f(1.160f, 0.119f);
    doVertex3f(-1.450f, 0.764f, 1.560f);
    doNormal3f(-0.962319f, 0.234615f, 0.137474f);
    doTexCoord2f(1.080f, 0.236f);
    doVertex3f(-1.510f, 0.382f, 2.050f);
    doTexCoord2f(1.190f, 0.146f);
    doVertex3f(-1.580f, 0.382f, 1.560f);
    doNormal3f(-0.986928f, -0.003154f, 0.161131f);
    doTexCoord2f(1.010f, 0.325f);
    doVertex3f(-1.560f, -0.010f, 2.050f);
    doTexCoord2f(0.912f, 0.468f);
    doVertex3f(-1.640f, -0.010f, 1.560f);
    doNormal3f(-0.961579f, -0.237688f, 0.137369f);
    doTexCoord2f(0.933f, 0.390f);
    doVertex3f(-1.510f, -0.383f, 2.050f);
    doNormal3f(-0.961237f, -0.239095f, 0.137320f);
    doTexCoord2f(0.850f, 0.509f);
    doVertex3f(-1.580f, -0.383f, 1.560f);
    doNormal3f(-0.935573f, -0.318389f, 0.152747f);
    doTexCoord2f(0.866f, 0.402f);
    doVertex3f(-1.370f, -0.765f, 2.050f);
    doTexCoord2f(0.822f, 0.484f);
    doVertex3f(-1.450f, -0.765f, 1.560f);
  glEnd();
  tris += 8;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-0.084890f, -0.996390f, 0.000000f);
    doTexCoord2f(0.583f, 0.312f);
    doVertex3f(-0.456f, -1.060f, 1.310f);
    doTexCoord2f(0.559f, 0.339f);
    doVertex3f(-0.456f, -1.060f, 1.040f);
    doNormal3f(0.143220f, -0.989691f, 0.000000f);
    doTexCoord2f(0.482f, 0.218f);
    doVertex3f(0.014f, -1.100f, 1.300f);
    doTexCoord2f(0.458f, 0.244f);
    doVertex3f(0.014f, -1.100f, 1.030f);
    doNormal3f(0.371709f, -0.928349f, 0.000000f);
    doTexCoord2f(0.279f, 0.051f);
    doVertex3f(0.912f, -0.749f, 1.300f);
    doTexCoord2f(0.248f, 0.084f);
    doVertex3f(0.912f, -0.749f, 1.030f);
    doNormal3f(0.379521f, -0.925183f, 0.000000f);
    doTexCoord2f(0.143f, -0.049f);
    doVertex3f(1.480f, -0.516f, 1.310f);
    doTexCoord2f(0.107f, -0.009f);
    doVertex3f(1.480f, -0.516f, 1.040f);
  glEnd();
  tris += 6;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(0.379521f, 0.925183f, 0.000000f);
    doTexCoord2f(0.581f, -0.519f);
    doVertex3f(1.480f, 0.516f, 1.310f);
    doTexCoord2f(0.617f, -0.559f);
    doVertex3f(1.480f, 0.516f, 1.040f);
    doNormal3f(0.371709f, 0.928349f, 0.000000f);
    doTexCoord2f(0.690f, -0.391f);
    doVertex3f(0.912f, 0.749f, 1.300f);
    doTexCoord2f(0.721f, -0.424f);
    doVertex3f(0.912f, 0.749f, 1.030f);
    doNormal3f(0.164178f, 0.986431f, 0.000000f);
    doTexCoord2f(0.872f, -0.201f);
    doVertex3f(0.014f, 1.100f, 1.300f);
    doTexCoord2f(0.895f, -0.226f);
    doVertex3f(0.014f, 1.100f, 1.030f);
    doNormal3f(-0.042560f, 0.999094f, 0.000000f);
    doTexCoord2f(0.973f, -0.107f);
    doVertex3f(-0.456f, 1.080f, 1.310f);
    doTexCoord2f(0.996f, -0.132f);
    doVertex3f(-0.456f, 1.080f, 1.040f);
  glEnd();
  tris += 6;

  glBegin(GL_TRIANGLE_STRIP);
    doNormal3f(-0.628337f, -0.777941f, 0.000000f);
    doTexCoord2f(0.706f, 0.220f);
    doVertex3f(-0.548f, -0.599f, 2.050f);
    doTexCoord2f(0.687f, 0.241f);
    doVertex3f(-0.548f, -0.599f, 1.920f);
    doNormal3f(-0.486915f, -0.873449f, 0.000000f);
    doTexCoord2f(0.669f, 0.204f);
    doVertex3f(-0.418f, -0.704f, 2.050f);
    doTexCoord2f(0.651f, 0.223f);
    doVertex3f(-0.418f, -0.704f, 1.920f);
    doNormal3f(-0.095369f, -0.995442f, 0.000000f);
    doTexCoord2f(0.606f, 0.158f);
    doVertex3f(-0.156f, -0.796f, 2.050f);
    doTexCoord2f(0.589f, 0.176f);
    doVertex3f(-0.156f, -0.796f, 1.920f);
    doNormal3f(0.417879f, -0.908502f, 0.000000f);
    doTexCoord2f(0.552f, 0.102f);
    doVertex3f(0.108f, -0.757f, 2.050f);
    doTexCoord2f(0.535f, 0.120f);
    doVertex3f(0.108f, -0.757f, 1.920f);
    doNormal3f(0.782548f, -0.622590f, 0.000000f);
    doTexCoord2f(0.532f, 0.067f);
    doVertex3f(0.238f, -0.644f, 2.050f);
    doTexCoord2f(0.514f, 0.087f);
    doVertex3f(0.238f, -0.644f, 1.920f);
    doNormal3f(0.970276f, -0.242000f, 0.000000f);
    doTexCoord2f(0.529f, 0.038f);
    doVertex3f(0.313f, -0.503f, 2.050f);
    doTexCoord2f(0.510f, 0.059f);
    doVertex3f(0.313f, -0.503f, 1.920f);
    doNormal3f(0.970276f, 0.242000f, 0.000000f);
    doTexCoord2f(0.695f, -0.140f);
    doVertex3f(0.313f, 0.503f, 2.050f);
    doTexCoord2f(0.715f, -0.161f);
    doVertex3f(0.313f, 0.503f, 1.920f);
    doNormal3f(0.782548f, 0.622590f, 0.000000f);
    doTexCoord2f(0.725f, -0.139f);
    doVertex3f(0.238f, 0.644f, 2.050f);
    doTexCoord2f(0.743f, -0.159f);
    doVertex3f(0.238f, 0.644f, 1.920f);
    doNormal3f(0.417879f, 0.908502f, 0.000000f);
    doTexCoord2f(0.760f, -0.122f);
    doVertex3f(0.108f, 0.757f, 2.050f);
    doTexCoord2f(0.778f, -0.140f);
    doVertex3f(0.108f, 0.757f, 1.920f);
    doNormal3f(-0.095369f, 0.995442f, 0.000000f);
    doTexCoord2f(0.820f, -0.072f);
    doVertex3f(-0.156f, 0.796f, 2.050f);
    doTexCoord2f(0.837f, -0.090f);
    doVertex3f(-0.156f, 0.796f, 1.920f);
    doNormal3f(-0.486915f, 0.873449f, 0.000000f);
    doTexCoord2f(0.871f, -0.013f);
    doVertex3f(-0.418f, 0.704f, 2.050f);
    doTexCoord2f(0.888f, -0.032f);
    doVertex3f(-0.418f, 0.704f, 1.920f);
    doNormal3f(-0.628337f, 0.777941f, 0.000000f);
    doTexCoord2f(0.890f, 0.022f);
    doVertex3f(-0.548f, 0.599f, 2.050f);
    doTexCoord2f(0.909f, 0.002f);
    doVertex3f(-0.548f, 0.599f, 1.920f);
  glEnd();
  tris += 22;

  glBegin(GL_TRIANGLE_FAN);
    doNormal3f(-0.085837f, 0.008268f, -0.996275f);
    doTexCoord2f(1.060f, 0.015f);
    doVertex3f(-0.964f, 0.765f, 1.510f);
    doNormal3f(-0.102340f, 0.000000f, -0.994749f);
    doTexCoord2f(0.711f, 0.394f);
    doVertex3f(-0.964f, -0.765f, 1.510f);
    doNormal3f(-0.075999f, -0.008443f, -0.997072f);
    doTexCoord2f(0.822f, 0.484f);
    doVertex3f(-1.450f, -0.765f, 1.560f);
    doNormal3f(-0.055963f, -0.013453f, -0.998342f);
    doTexCoord2f(0.850f, 0.509f);
    doVertex3f(-1.580f, -0.383f, 1.560f);
    doNormal3f(-0.075843f, 0.001825f, -0.997118f);
    doTexCoord2f(0.912f, 0.468f);
    doVertex3f(-1.640f, -0.010f, 1.560f);
    doNormal3f(-0.102349f, 0.034831f, -0.994139f);
    doTexCoord2f(1.190f, 0.146f);
    doVertex3f(-1.580f, 0.382f, 1.560f);
    doTexCoord2f(1.160f, 0.119f);
    doVertex3f(-1.450f, 0.764f, 1.560f);
  glEnd();
  tris += 5;

  glBegin(GL_TRIANGLE_FAN);
    doNormal3f(0.158932f, -0.015248f, 0.987172f);
    doTexCoord2f(0.999f, 0.075f);
    doVertex3f(-0.946f, 0.762f, 1.970f);
    doNormal3f(0.184674f, -0.067682f, 0.980467f);
    doTexCoord2f(1.080f, 0.169f);
    doVertex3f(-1.370f, 0.764f, 2.050f);
    doNormal3f(0.169066f, -0.043637f, 0.984638f);
    doTexCoord2f(1.080f, 0.236f);
    doVertex3f(-1.510f, 0.382f, 2.050f);
    doNormal3f(0.132108f, -0.002352f, 0.991233f);
    doTexCoord2f(1.010f, 0.325f);
    doVertex3f(-1.560f, -0.010f, 2.050f);
    doNormal3f(0.095928f, 0.022277f, 0.995139f);
    doTexCoord2f(0.933f, 0.390f);
    doVertex3f(-1.510f, -0.383f, 2.050f);
    doNormal3f(0.185408f, 0.000000f, 0.982662f);
    doTexCoord2f(0.866f, 0.402f);
    doVertex3f(-1.370f, -0.765f, 2.050f);
    doTexCoord2f(0.766f, 0.326f);
    doVertex3f(-0.946f, -0.766f, 1.970f);
  glEnd();
  tris += 5;

  return tris;
}
/*
 * Local Variables: ***
 * mode:C ***
 * tab-width: 8 ***
 * c-basic-offset: 2 ***
 * indent-tabs-mode: t ***
 * End: ***
 * ex: shiftwidth=2 tabstop=8
 */
