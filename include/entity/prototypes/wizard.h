/**
 * wizard
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * wizard entity
*/

#ifndef _WIZARD_H_
#define _WIZARD_H_

#include "../entity.h"

#include "player.h"
#include "projectile.h"

#include "../../world/room.h"

#include "../../utils/types.h"

/**
 * Ranged attack (projectile creating)
 * 
 * @param _wizard           existing wizard
 * @param _active_room      active room
*/
void wizardAttack(Entity* _wizard, Room* _active_room);

/**
 * Calculates damage by looking at characteristics 
 * 
 * @param _wizard      existing wizard
 * 
 * @return Calculated damage
*/
i32 wizardCalculateDamage(Entity* _wizard);

#endif
