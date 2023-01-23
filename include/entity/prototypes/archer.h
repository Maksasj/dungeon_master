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

#include "../entity.h"

#include "player.h"
#include "projectile.h"

#include "../../world/room.h"

#include "../../utils/types.h"

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _archer      existing archer
 * 
 * @return Calculated damage
*/
i32 archerCalculateDamage(Entity* _archer);

#endif
