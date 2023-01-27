#ifndef _SYMMETRIC_1_ROOM_H_
#define _SYMMETRIC_1_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void symmetric1RoomInit(Room* _self);

void symmetric1RoomRender(Room* _self, void* _world);

void symmetric1RoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
