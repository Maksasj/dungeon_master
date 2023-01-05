#ifndef _WIZARD_H_

#include "entity.h"

#include "../world/room.h"

#include "../utils/types.h"

void wizardAttack(Entity* _self, Room* _active_room);
i32 wizardCalculateDamage(Entity* _self);

#endif
