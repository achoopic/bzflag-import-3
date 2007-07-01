/* bzflag
 * Copyright (c) 1993 - 2007 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * Remote Control Request: Encapsulates requests between backend and frontend
 */

#ifndef	BZF_RC_REQUEST_H
#define	BZF_RC_REQUEST_H

#include "common.h"
#include <map>

typedef enum {
  InvalidRequest,
  HelloRequest,
  setSpeed,
  setTurnRate,
  setAhead,
  setTurnLeft,
  setFire,
  getGunHeat,
  getDistanceRemaining,
  getTurnRemaining,
  getTickRemaining,
  getTickDuration,
  setTickDuration,
  execute,
  TeamListRequest,
  BasesListRequest,
  ObstacleListRequest,
  FlagListRequest,
  ShotListRequest,
  MyTankListRequest,
  OtherTankListRequest,
  ConstListRequest,
  RequestCount
} AgentReqType;

class RCLink;

class RCRequest {
  public:
    /* These are static functions to allow for instantiation
     * of classes based on a string (the request command name) */
    static void initializeLookup();
    static RCRequest *getRequestInstance(std::string request);

    RCRequest();
    RCRequest(AgentReqType reqtype);
    RCRequest(int argc, char **argv);

    RCRequest *getNext();
    void append(RCRequest *newreq);

    int getRobotIndex();
    AgentReqType getRequestType();
    void sendAck(RCLink *link);
    void sendFail(RCLink *link);

    float distance, turn;
    float speed, turnRate;
    float duration;
    bool fail;
    char *failstr;

  private:
    /* These are static data and functions to allow for instantiation 
     * of classes based on a string (the request command name) */
    static std::map<std::string, RCRequest* (*)()> requestLookup;
    template <typename T>
     static RCRequest* instantiate() { return new T; }

    void setRobotIndex(char *arg);
    template <class T>
      T clamp(T val, T min, T max);

    AgentReqType requestType;
    int robotIndex;
    RCRequest *next;
};

#include "RCLink.h"

#endif

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
