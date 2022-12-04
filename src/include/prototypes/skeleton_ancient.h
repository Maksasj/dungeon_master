#ifndef _SKELETON_ANCIENT_H_
#define _SKELETON_ANCIENT_H_

#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

#define _GRID_LENGTH_ 12
#define _GRID_HEIGHT_ 7

void skeletonAncientUpdate(Entity* _self, World* _world, Room* _room);

void skeletonAncientKill(Entity* _self);

i32 skeletonAncientCalculateDamage();

#endif
