#ifndef _SPIKE_MADNESS_ROOM_H_
#define _SPIKE_MADNESS_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void spikeMadnessRoomInit(Room* _self);

void spikeMadnessRoomRender(Room* _self, void* _world);

void spikeMadnessRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
