#ifndef _ICE_SWORD_H
#define _ICE_SWORD_H

#include "../../entity/prototypes/player.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

#define _ATTACK_OFFSET_ 8

void iceSwordUseCallback(Entity* _use_target, Room* _active_room);

#endif
