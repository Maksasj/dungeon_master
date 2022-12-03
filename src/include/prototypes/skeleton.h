#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

#define _GRID_LENGTH_ 12
#define _GRID_HEIGHT_ 7

void skeleton_update(Entity* _self, World* _world, Room* _room);

void skeleton_kill(Entity* _self);

i32 skeletonCalculateDamage(Entity* _self);

#endif
