/**
 * skeleton_ancient
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Ancient skeleton entity
*/

#ifndef _SKELETON_ANCIENT_H_
#define _SKELETON_ANCIENT_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

/**
 * Updates ancient skeleton in worldUpdate
 * 
 * @param _self         existing ancient skeleton
 * @param _world        existing world
 * @param _room         existing room
*/
void skeletonAncientUpdate(Entity* _self, World* _world, Room* _room);

/**
 * Kills ancient skeleton
 * 
 * @param _self         existing ancient skeleton
*/
void skeletonAncientKill(Entity* _self);

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _self      existing ancient skeleton
 * 
 * @return Calculated damage
*/
i32 skeletonAncientCalculateDamage(Entity* _self);

/**
 * Calculates with pseudo-number generator dodge chance
 * 
 * @param _self      existing ancient skeleton
 * 
 * @return 0 - receives damage (false), 1 - dodged (true)
*/
i32 skeletonAncientTryDodge(Entity* _self);

#endif
