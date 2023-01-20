/**
 * projectile
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * projectile entity
*/

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "../entity.h"
#include "../../utils/types.h"
#include "../../world/world.h"

#include "../../utils/logger.h"

/**
 * Initialize projectile
 * 
 * @param _position         coordinates
 * @param _layer            layer
 * @param _sprite_offset    sprite offset
 * 
 * @return projectile object
*/
Entity projectileInit(ivec2 _position, LayerMask _layer, u32 _sprite_offset);

/**
 * Updates projectile in worldUpdate
 * 
 * @param _self         existing projectile
 * @param _world        existing world
 * @param _room         existing room
*/
void projectileUpdate(Entity* _self, World* _world, Room* _room);

/**
 * Destroys projectile
 * 
 * @param _self         existing projectile
*/
void destroyProjectile(Entity* _self);

void rotateProjectile(Entity* _projectile, Facing _direction, i32 sprite_offset_horizontal, i32 sprite_offset_vetical);

#endif
