#ifndef _DUMBBELL_ROOM_H_
#define _DUMBBELL_ROOM_H_

#include "../../item/item_macros.h"
#include "../../entity/entity_macros.h"
#include "../../entity/prototypes/player.h"
#include "../tile.h"

void dumbbellRoomInit(Room* _self, Entity* _player);;

void dumbbellRoomRender(Room* _self, void* _world);

void dumbbellRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
