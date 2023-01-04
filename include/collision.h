#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "utils/types.h"

typedef enum CollisionType {
    WALL,
    
    OPENED_DOOR,
    CLOSED_DOOR,
    
    CHEST,
    
    NEXT_FLOOR_ENTRANCE,

    NONE
} CollisionType;

#endif
