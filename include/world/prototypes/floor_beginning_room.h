#ifndef _FLOOR_BEGINNING_ROOM_H_
#define _FLOOR_BEGINNING_ROOM_H_

#include "../room.h"

void FloorBeginningRoomInit(Room* _self);

void FloorBeginningRoomRender(Room* _self);

void FloorBeginningRoomUpdateCallback(Room* _self, Entity* _player);

#endif
