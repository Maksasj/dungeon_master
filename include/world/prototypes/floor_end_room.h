#ifndef _FLOOR_END_ROOM_H_
#define _FLOOR_END_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void floorEndRoomInit(Room* _self);

void floorEndRoomRender(Room* _self, void* _world);

void floorEndRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
