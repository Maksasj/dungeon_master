#ifndef _TWO_NINJA_SKELETON_ROOM_H_
#define _TWO_NINJA_SKELETON_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void twoNinjaSkeletonRoomInit(Room* _self);

void twoNinjaSkeletonRoomRender(Room* _self, void* _world);

void twoNinjaSkeletonRoomUpdateCallback(Room* _self, Entity* _player);

#endif
