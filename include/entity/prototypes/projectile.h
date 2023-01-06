#ifndef _PROJECTILE_H_

#include "../entity.h"
#include "../../utils/types.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

Entity projectileInit(fvec2 _position, u32 _sprite_offset);

void projectileUpdate(Entity* _self, World* _world, Room* _room);

i32 projectileCalculateDamage(Entity* _self);

void destroyProjectile(Entity* _self);

#endif
