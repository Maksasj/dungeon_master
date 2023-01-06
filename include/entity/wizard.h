#ifndef _WIZARD_H_

#include "entity.h"

#include "prototypes/player.h"

#include "../world/room.h"

#include "../utils/types.h"

void wizardAttack(Entity* _wizard, Room* _active_room);
i32 wizardCalculateDamage(Entity* _wizard);

#endif
