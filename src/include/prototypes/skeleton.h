#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../world/room.h"
#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

#define _ATTACK_COOLDOWN_ 2

void skeleton_update(Entity* _self, World* _world, Room* _room);

void skeleton_kill(Entity* _self);

i32 skeletonCalculateDamage();

void skeletonSetAttackCooldown(Entity* _self);

#endif
