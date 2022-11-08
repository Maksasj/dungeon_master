#include "include/background.h"

#include "assets/background.h"
#include "assets/map.h"

/* return a pointer to one of the 4 character blocks (0-3) */
vu16* charBlock(u32 _block) {
    /* they are each 16K big */
    return (vu16*) (_TILEMAP_ + (_block * _CHAR_BLOCK_SIZE_));
}

/* return a pointer to one of the 32 screen blocks (0-31) */
vu16* screenBlock(u32 _block) {
    /* they are each 2K big */
    return (vu16*) (_TILEMAP_ + (_block * _SCREEN_BLOCK_SIZE_));
}

/* function to setup background 0 for this program */
void setupBackground() {

    /* load the palette from the image into palette memory*/
    memcpy16DMA((u16*) _BG_PALETTE_, (u16*) BACKGROUND_PALETTE, _PALETTE_SIZE_);

    /* load the image into char block 0 */
    memcpy16DMA((u16*) charBlock(0), (u16*) BACKGROUND_DATA,
            (_BACKGROUND_WIDTH_ * _BACKGROUND_HEIGHT_) / 2);

    /* set all control the bits in this register */
    *_BG0_CONTROL_ = 0 |    /* priority, 0 is highest, 3 is lowest */
        (0 << 2)  |       /* the char block the image data is stored in */
        (0 << 6)  |       /* the mosaic flag */
        (1 << 7)  |       /* color mode, 0 is 16 colors, 1 is 256 colors */
        (16 << 8) |       /* the screen block the tile data is stored in */
        (1 << 13) |       /* wrapping flag */
        (0 << 14);        /* bg size, 0 is 256x256 */

    /* load the tile data into screen block 16 */
    memcpy16DMA((u16*) screenBlock(16), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
}
