#ifndef _SKELETON_KING_H_
#define _SKELETON_KING_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

void skeletonKingUpdate(Entity* _self, World* _world, Room* _room);

void skeletonKingKill(Entity* _self);

i32 skeletonKingCalculateDamage(Entity* _self);

i32 skeletonKingTryDodge(Entity* _self);

#endif
