/**
 * gfx
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows manipulate with GBA graphics
*/

#ifndef _GFX_H_
#define _GFX_H_

#include "types.h"

// Screen resolution
#define _SCREEN_WIDTH_  240
#define _SCREEN_HEIGHT_ 160

// LCD Control
#define _DISPLAY_CONTROL_   ((vu32*) 0x4000000)
// General LCD Status
#define _DISPLAY_STATUS_    ((vu16*) 0x4000004)
// Vertical Counter
#define _SCANLINE_COUNTER_  ((vu16*) 0x4000006)

// Display Control Mode 0 bit
#define _DISPLAY_CONTROL_MODE_0_    0x00

// Background bits
#define _DISPLAY_CONTROL_BG_0_      0x100 
#define _DISPLAY_CONTROL_BG_1_      0x200 
#define _DISPLAY_CONTROL_BG_2_      0x400 
#define _DISPLAY_CONTROL_BG_3_      0x800 

// Sprite bits
#define _SPRITE_MAP_2D_ 0x0
#define _SPRITE_MAP_1D_ 0x40
#define _SPRITE_ENABLE_ 0x1000

// OBJ Tiles
#define _SPRITE_IMAGE_MEMORY_ ((vu16*) 0x6010000)
// OBJ Palette RAM (512 bytes, 256 colors)
#define _SPRITE_PALETTE_ ((vu16*) 0x5000200)

/**
 * Wait for the scanlines to reach the beginning of the screen
*/
void waitVBlank();

#endif
