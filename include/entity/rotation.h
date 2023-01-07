/**
 * Rotation
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains defenition for all possible rotations
*/

#ifndef _ROTATION_H_
#define _ROTATION_H_

/* Enum that defenies all rotations */
typedef enum Facing {
    UP,
    RIGHT,
    DOWN,
    LEFT
} Facing;

/**
 * Returns opposite rotations
 * 
 * @param facing Facing side
 * @return Opposite facing side
*/
Facing getOppositeFacing(Facing facing);

#endif
