#ifndef _WARRIOR_H_

#include "entity.h"
#include "prototypes/player.h"

#include "../world/room.h"

#include "../utils/types.h"

#define _ATTACK_OFFSET_ 8

void warriorAttack(Entity* _warrior, Room* _active_room);
i32 warriorCalculateDamage(Entity* _warrior);

#endif
