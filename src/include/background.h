#ifndef BUTTONS_H
#define BUTTONS_H

#include "defines.h"
#include "sprite.h"

#include "../assets/background.h"
#include "../assets/map.h"

/* return a pointer to one of the 4 character blocks (0-3) */
volatile unsigned short* char_block(unsigned long block);

/* return a pointer to one of the 32 screen blocks (0-31) */
volatile unsigned short* screen_block(unsigned long block);

/* function to setup background 0 for this program */
void setup_background();

#endif
