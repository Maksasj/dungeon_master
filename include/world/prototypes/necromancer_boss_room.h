#ifndef _NECROMANCER_BOSS_ROOM_H_
#define _NECROMANCER_BOSS_ROOM_H_

#include "../../entity/entity_macros.h"
#include "../tile.h"

void necromancerBossRoomInit(Room* _self);

void necromancerBossRoomRender(Room* _self, void* _world);

void necromancerBossRoomUpdateCallback(void* _world, Room* _self, Entity* _player);

#endif
