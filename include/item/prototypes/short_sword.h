#ifndef _SHORT_SWORD_H
#define _SHORT_SWORD_H

#include "../../entity/prototypes/player.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

#define _ATTACK_OFFSET_ 8

void shortSwordUseCallback(Entity* _use_target, Room* _active_room);

#endif
