#ifndef _CORRIDORS_ROOM_H_
#define _CORRIDORS_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void corridorsRoomInit(Room* _self);

void corridorsRoomRender(Room* _self, void* _world);

void corridorsRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
