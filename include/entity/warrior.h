#ifndef _WARRIOR_H_

#include "entity.h"

#include "../world/room.h"

#include "../utils/types.h"

void warriorAttack(Entity* _self, Room* _active_room);
i32 warriorCalculateDamage(Entity* _self);

#endif
