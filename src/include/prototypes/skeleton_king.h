#ifndef _SKELETON_KING_H_
#define _SKELETON_KING_H_

#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

#define _GRID_LENGTH_ 12
#define _GRID_HEIGHT_ 7

void skeletonKingUpdate(Entity* _self, World* _world, Room* _room);

void skeletonKingKill(Entity* _self);

i32 skeletonKingCalculateDamage();

#endif
