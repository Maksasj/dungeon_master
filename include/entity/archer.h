/**
 * archer
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * archer entity
*/

#ifndef _ARCHER_H_
#define _ARCHER_H_

#include "entity.h"
#include "prototypes/player.h"
#include "prototypes/projectile.h"

#include "../world/room.h"

#include "../utils/types.h"

/**
 * Ranged attack (projectile creating)
 * 
 * @param _archer           existing archer
 * @param _active_room      active room
*/
void archerAttack(Entity* _archer, Room* _active_room);

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _archer      existing archer
 * 
 * @return Calculated damage
*/
i32 archerCalculateDamage(Entity* _archer);

#endif
