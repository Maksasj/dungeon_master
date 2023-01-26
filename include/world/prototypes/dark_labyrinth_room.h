#ifndef _DARK_LABYRINTH_ROOM_H_
#define _DARK_LABYRINTH_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../../item/item_macros.h"

#include "../tile.h"

void darkLabyrinthRoomInit(Room* _self, Entity* _player);

void darkLabyrinthRoomRender(Room* _self, void* _world);

void darkLabyrinthRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
