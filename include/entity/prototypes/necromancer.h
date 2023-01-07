/**
 * necromancer
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * necromancer entity
*/

#ifndef _NECROMANCER_H_
#define _NECROMANCER_H_

#include "../../world/world.h"
#include "../../sound/sound.h"
#include "../entity.h"

// structure for storing necromancer specs
typedef struct NecromancerSpec {
    // summon skeletons cooldown
    i32 summonCooldown;
} NecromancerSpec;

/**
 * Updates necromancer in worldUpdate
 * 
 * @param _self         existing necromancer
 * @param _world        existing world
 * @param _room         existing room
*/
void necromancerUpdate(Entity* _self, World* _world, Room* _room);

/**
 * Kills necromancer
 * 
 * @param _self         existing necromancer
*/
void necromancerKill(Entity* _self);

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _self      existing necromancer
 * 
 * @return Calculated damage
*/
i32 necromancerCalculateDamage(Entity* _self);

/**
 * Calculates with pseudo-number generator dodge chance
 * 
 * @param _self      existing necromancer
 * 
 * @return 0 - receives damage (false), 1 - dodged (true)
*/
i32 necromancerTryDodge(Entity* _self);

#endif
