#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "types.h"

typedef enum CollisionType {
    WALL,
    
    OPENED_DOOR,
    CLOSED_DOOR,
    
    CHEST,
    
    ENEMY,

    NONE
} CollisionType;

#endif
