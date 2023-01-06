#ifndef _ARCHER_H_

#include "entity.h"
#include "prototypes/player.h"
#include "prototypes/projectile.h"

#include "../world/room.h"

#include "../utils/types.h"

void archerAttack(Entity* _archer, Room* _active_room);
i32 archerCalculateDamage(Entity* _archer);

#endif
