#ifndef _LABYRINTH_1_ROOM_H_
#define _LABYRINTH_1_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../../item/item_macros.h"

#include "../tile.h"

void labyrinth1RoomInit(Room* _self, Entity* _player);

void labyrinth1RoomRender(Room* _self, void* _world);

void labyrinth1RoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
