#ifndef _KING_IN_CORRIDOR_ROOM_H_
#define _KING_IN_CORRIDOR_ROOM_H_

#include "../../item/item_macros.h"
#include "../../entity/entity_macros.h"
#include "../../entity/prototypes/player.h"
#include "../tile.h"

void kingInCorridorRoomInit(Room* _self, Entity* _player);

void kingInCorridorRoomRender(Room* _self, void* _world);

void kingInCorridorRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
