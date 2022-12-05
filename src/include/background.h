#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "utils/types.h"
#include "sprite.h"

#define _TILEMAP_               0x6000000
#define _CHAR_BLOCK_SIZE_       0x4000  
#define _SCREEN_BLOCK_SIZE_     0x800

#define _BG_PALETTE_ ((vu16*) 0x5000000)

#define _BG0_CONTROL_ ((vu16*) 0x4000008)

#define _BG0_X_SCROLL_ ((u16*) 0x4000010)
#define _BG0_Y_SCROLL_ ((u16*) 0x4000012)

vu16* charBlock(u32 _block);

vu16* screenBlock(u32 _block);

void initBackground();

#endif
