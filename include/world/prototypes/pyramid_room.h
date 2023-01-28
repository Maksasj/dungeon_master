#ifndef _PYRAMID_ROOM_H_
#define _PYRAMID_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void pyramidRoomInit(Room* _self);

void pyramidRoomRender(Room* _self, void* _world);

void pyramidRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
