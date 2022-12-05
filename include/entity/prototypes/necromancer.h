#ifndef _NECROMANCER_H_
#define _NECROMANCER_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

typedef struct NecromancerSpec {
    i32 summonCooldown;
} NecromancerSpec;

void necromancerUpdate(Entity* _self, World* _world, Room* _room);

void necromancerKill(Entity* _self);

i32 necromancerCalculateDamage(Entity* _self);

i32 necromancerTryDodge(Entity* _self);

#endif
