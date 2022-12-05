#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../world/world.h"
#include "../entity.h"
#include "../sound/sound.h"

void skeleton_update(Entity* _self, World* _world, Room* _room);

void skeleton_kill(Entity* _self);

i32 skeletonCalculateDamage(Entity* _self);

i32 skeleton_try_dodge(Entity* _self);

#endif
