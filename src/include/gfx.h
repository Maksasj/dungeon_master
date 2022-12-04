#ifndef _GFX_H_
#define _GFX_H_

#include "types.h"

#define _SCREEN_WIDTH_  240
#define _SCREEN_HEIGHT_ 160

#define _DISPLAY_CONTROL_   ((vu32*) 0x4000000)
#define _DISPLAY_STATUS_    ((vu16*) 0x4000004)
#define _SCANLINE_COUNTER_  ((vu16*) 0x4000006)

#define _DISPLAY_CONTROL_MODE_0_    0x00
#define _DISPLAY_CONTROL_BG_0_      0x100 

#define _SPRITE_MAP_2D_ 0x0
#define _SPRITE_MAP_1D_ 0x40
#define _SPRITE_ENABLE_ 0x1000

#define _SPRITE_IMAGE_MEMORY_ ((vu16*) 0x6010000)

#define _SPRITE_PALETTE_ ((vu16*) 0x5000200)

void waitVBlank();

void onVBlank();

#endif
