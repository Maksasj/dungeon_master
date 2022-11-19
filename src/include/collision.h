#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "types.h"

typedef enum COLLISION_TYPE {
    WALL,
    
    OPENED_DOOR,
    CLOSED_DOOR,
    
    CHEST,
    
    ENEMY,

    NONE
} COLLISION_TYPE;

#endif
