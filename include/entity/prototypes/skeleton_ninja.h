/**
 * skeleton_ninja
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Skeleton ninja entity
*/

#ifndef _SKELETON_NINJA_H_
#define _SKELETON_NINJA_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

/**
 * Updates ninja skeleton in worldUpdate
 * 
 * @param _self         existing ninja skeleton
 * @param _world        existing world
 * @param _room         existing room
*/
void skeletonNinjaUpdate(Entity* _self, World* _world, Room* _room);

/**
 * Kills ninja skeleton
 * 
 * @param _self         existing ninja skeleton
*/
void skeletonNinjaKill(Entity* _self);

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _self      existing ninja skeleton
 * 
 * @return Calculated damage
*/
i32 skeletonNinjaCalculateDamage(Entity* _self);

/**
 * Calculates with pseudo-number generator dodge chance
 * 
 * @param _self      existing ninja skeleton
 * 
 * @return 0 - receives damage (false), 1 - dodged (true)
*/
i32 skeletonNinjaTryDodge(Entity* _self);

#endif
