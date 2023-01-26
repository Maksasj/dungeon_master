#ifndef _FOUR_ANCIENT_SKELETON_ROOM_H_
#define _FOUR_ANCIENT_SKELETON_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void fourAncientSkeletonRoomInit(Room* _self);

void fourAncientSkeletonRoomRender(Room* _self, void* _world);

void fourAncientSkeletonRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
