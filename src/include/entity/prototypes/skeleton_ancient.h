#ifndef _SKELETON_ANCIENT_H_
#define _SKELETON_ANCIENT_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

void skeletonAncientUpdate(Entity* _self, World* _world, Room* _room);

void skeletonAncientKill(Entity* _self);

i32 skeletonAncientCalculateDamage(Entity* _self);

i32 skeletonAncientTryDodge(Entity* _self);

#endif
