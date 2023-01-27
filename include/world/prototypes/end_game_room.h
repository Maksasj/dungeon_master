#ifndef _END_GAME_ROOM_H_
#define _END_GAME_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void endGameRoomInit(Room* _self);

void endGameRoomRender(Room* _self, void* _world);

void endGameRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
