#ifndef _PROJECTILE_H_

#include "../entity.h"
#include "../../utils/types.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

typedef struct ProjectileSpec {
    Facing host_facing;
} ProjectileSpec;

void projectileUpdate(Entity* _self, World* _world, Room* _room);

Entity projectileInit(fvec2 _position, u32 _sprite_offset);

void destroyProjectile(Entity* _self);

#endif
