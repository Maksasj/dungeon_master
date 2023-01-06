#ifndef _PROJECTILE_H_

#include "../entity.h"
#include "../../utils/types.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

Entity projectileInit(ivec2 _position, LayerMask _layer, u32 _sprite_offset);

void projectileUpdate(Entity* _self, World* _world, Room* _room);

void destroyProjectile(Entity* _self);

#endif
