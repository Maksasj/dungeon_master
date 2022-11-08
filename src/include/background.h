#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "types.h"
#include "sprite.h"

#define _TILEMAP_               0x6000000
#define _CHAR_BLOCK_SIZE_       0x4000  
#define _SCREEN_BLOCK_SIZE_     0x800

/* the address of the color palettes used for backgrounds */
#define _BG_PALETTE_ ((vu16*) 0x5000000)

/* the control registers for the four tile layers */
#define _BG0_CONTROL_ ((vu16*) 0x4000008)

/* scrolling registers for backgrounds */
#define _BG0_X_SCROLL_ ((u16*) 0x4000010)
#define _BG0_Y_SCROLL_ ((u16*) 0x4000012)

/* return a pointer to one of the 4 character blocks (0-3) */
vu16* charBlock(u32 _block);

/* return a pointer to one of the 32 screen blocks (0-31) */
vu16* screenBlock(u32 _block);

/* function to setup background 0 for this program */
void setupBackground();

#endif
