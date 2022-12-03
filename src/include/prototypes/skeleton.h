#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "../world.h"
#include "../entity/entity.h"
#include "../sound.h"

void skeleton_update(Entity* _self, World* _world, Room* _room);

void skeleton_kill(Entity* _self);

#endif
