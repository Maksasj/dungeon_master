#ifndef _SYMMETRIC_2_ROOM_H_
#define _SYMMETRIC_2_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void symmetric2RoomInit(Room* _self);

void symmetric2RoomRender(Room* _self, void* _world);

void symmetric2RoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
