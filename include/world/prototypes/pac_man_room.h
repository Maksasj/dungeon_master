#ifndef _PAC_MAN_ROOM_H_
#define _PAC_MAN_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void pacmanRoomInit(Room* _self);

void pacmanRoomRender(Room* _self, void* _world);

void pacmanRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
