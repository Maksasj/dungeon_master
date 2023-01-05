#ifndef _ARCHER_H_

#include "entity.h"

#include "../world/room.h"

#include "../utils/types.h"

void archerAttack(Entity* _self, Room* _active_room);
i32 archerCalculateDamage(Entity* _self);

#endif
