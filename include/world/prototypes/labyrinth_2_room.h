#ifndef _LABYRINTH_2_ROOM_H_
#define _LABYRINTH_2_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../../item/item_macros.h"

#include "../tile.h"

void labyrinth2RoomInit(Room* _self, Entity* _player);

void labyrinth2RoomRender(Room* _self, void* _world);

void labyrinth2RoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
