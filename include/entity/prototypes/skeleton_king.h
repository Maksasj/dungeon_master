/**
 * skeleton_king
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Skeleton king entity
*/

#ifndef _SKELETON_KING_H_
#define _SKELETON_KING_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

/**
 * Updates king skeleton in worldUpdate
 * 
 * @param _self         existing king skeleton
 * @param _world        existing world
 * @param _room         existing room
*/
void skeletonKingUpdate(Entity* _self, World* _world, Room* _room);

/**
 * Kills king skeleton
 * 
 * @param _self         existing king skeleton
*/
void skeletonKingKill(Entity* _self);

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _self      existing king skeleton
 * 
 * @return Calculated damage
*/
i32 skeletonKingCalculateDamage(Entity* _self);

/**
 * Calculates with pseudo-number generator dodge chance
 * 
 * @param _self      existing king skeleton
 * 
 * @return 0 - receives damage (false), 1 - dodged (true)
*/
i32 skeletonKingTryDodge(Entity* _self);

#endif
