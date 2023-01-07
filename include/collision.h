/**
 * Collision
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains definition of all collision types
*/

#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "utils/types.h"

/* Enum that contains all definet collision types */
typedef enum CollisionType {
    WALL,
    TRAP,
    
    OPENED_DOOR,
    CLOSED_DOOR,
    
    NEXT_FLOOR_ENTRANCE,

    NONE
} CollisionType;

#endif
