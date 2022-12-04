#ifndef _SKELETON_NINJA_H_
#define _SKELETON_NINJA_H_

#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

#define _GRID_LENGTH_ 12
#define _GRID_HEIGHT_ 7

void skeletonNinjaUpdate(Entity* _self, World* _world, Room* _room);

void skeletonNinjaKill(Entity* _self);

i32 skeletonCalculateDamage();

#endif
