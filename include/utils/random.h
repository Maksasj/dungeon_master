/**
 * random
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Generating pseudo-random numbers
*/

#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "types.h"

/* Global random next seed variable */
extern u32 RAND_NEXT;

/**
 * Function, that generates pseudo-random number
 * 
 * @return pseudo-random number
*/
u32 random();

/**
 * Setting seed for pseudo-random number generator
 * 
 * @param _seed     seed for generator
*/
void setSeed(u32 _seed);

#endif
