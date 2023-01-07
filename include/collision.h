#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "utils/types.h"

typedef enum CollisionType {
    WALL,
    TRAP,
    
    OPENED_DOOR,
    CLOSED_DOOR,
    
    NEXT_FLOOR_ENTRANCE,

    NONE
} CollisionType;

#endif
