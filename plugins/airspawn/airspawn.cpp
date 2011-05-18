// airspawn.cpp : Defines the entry point for the DLL application.
//

#include "bzfsAPI.h"
#include <string>
#include <map>
#include <cstdlib>

// plugin definition

class airspawn : public bz_Plugin
{
public:

  virtual const char* Name (){return "Airspawn";}
  virtual void Init ( const char* config);
  virtual void Event ( bz_EventData *eventData );

  float spawnRange;
};

BZ_PLUGIN(airspawn)

void airspawn::Init ( const char* commandLine )
{
  bz_debugMessage(4,"airspawn plugin loaded");

  spawnRange = 0;
  if ( commandLine )
    spawnRange = (float)atof(commandLine);
  if ( spawnRange < 0.001f )
    spawnRange = 10.0f;

  Register(bz_eGetPlayerSpawnPosEvent);
}

void airspawn::Event ( bz_EventData *eventData )
{
  switch (eventData->eventType)
  {
	case bz_eGetPlayerSpawnPosEvent:
    {
      bz_GetPlayerSpawnPosEventData *spawn = (bz_GetPlayerSpawnPosEventData*)eventData;

      float randPos = rand()/(float)RAND_MAX;
      spawn->pos[2] += randPos * spawnRange;
      spawn->handled = true;
    }
    break;
  }
}

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

