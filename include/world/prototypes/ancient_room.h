#ifndef _ANCIENT_ROOM_H_
#define _ANCIENT_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void ancientRoomInit(Room* _self);

void ancientRoomRender(Room* _self, void* _world);

void ancientRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
