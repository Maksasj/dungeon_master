#ifndef _DARK_CLAYMORE_H
#define _DARK_CLAYMORE_H

#include "../../entity/prototypes/player.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

#define _ATTACK_OFFSET_ 8

void darkClaymoreUseCallback(Entity* _use_target, Room* _active_room);

#endif
