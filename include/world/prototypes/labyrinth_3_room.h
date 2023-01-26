#ifndef _LABYRINTH_3_ROOM_H_
#define _LABYRINTH_3_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../../item/item_macros.h"

#include "../tile.h"

void labyrinth3RoomInit(Room* _self, Entity* _player);

void labyrinth3RoomRender(Room* _self, void* _world);

void labyrinth3RoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
