/* bzflag
 * Copyright (c) 1993-2010 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef __FLAGINFO_H__
#define __FLAGINFO_H__

/* bzflag common header */
#include "common.h"

/* system headers */
#include <stdlib.h>

/* bzflag common headers */
#include "Flag.h"
#include "BzTime.h"
#include "vectors.h"


class NetMessage;


/** FlagInfo describes a flag as it pertains to the world.
 */
class FlagInfo {
  public:

    FlagInfo();

    void setRequiredFlag(FlagType* desc);
    void addFlag();
    void* pack(void* buf, bool hide = false);
    size_t pack(NetMessage& netMsg , bool hide = false);
    void dropFlag(const fvec3& pos, const fvec3& landingPos, bool vanish);
    void resetFlag(const fvec3& pos, bool teamIsEmpty);
    void grab(int playerIndex);
    int  teamIndex() const;
    int  getIndex() const;
    bool landing(const BzTime& tm);
    void getTextualInfo(char* message);
    bool exist() const;

    static FlagInfo* get(int index);
    static void setSize(int _numFlags);
    static void setAllowed(std::vector<FlagType*> allowed);
    static void setExtra(int extra);
    static int  lookupFirstTeamFlag(int teamindex);
    static float getNextDrop(BzTime& tm);
    static void  setNoFlagInAir();

    // flag info
    Flag flag;
    // player index who has flag
    int player;
    // how many grabs before removed
    int grabs;
    // true if flag must be in game
    bool required;
    // number of shots on this flag
    int numShots;

  private:
    int flagIndex;
    static std::vector<FlagType*> allowedFlags;
    static int        numExtraFlags;
    static int        numFlags;
    static int        numFlagsInAir;
    static FlagInfo*       flagList;

    // time flag will land
    BzTime        dropDone;
};
#else
class FlagInfo;
#endif

// Local Variables: ***
// mode: C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: nil ***
// End: ***
// ex: shiftwidth=2 tabstop=8 expandtab