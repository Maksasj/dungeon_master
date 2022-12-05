#ifndef _SKELETON_NINJA_H_
#define _SKELETON_NINJA_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

void skeletonNinjaUpdate(Entity* _self, World* _world, Room* _room);

void skeletonNinjaKill(Entity* _self);

i32 skeletonNinjaCalculateDamage(Entity* _self);

i32 skeletonNinjaTryDodge(Entity* _self);

#endif
