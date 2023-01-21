#include "../include/background.h"

void initBackground(u16* _pallete, u16* _data, i32 _width, i32 _height) {
    memcpy16DMA((u16*) _BG_PALETTE_, (u16*) _pallete, _PALETTE_SIZE_);
    memcpy16DMA((u16*) charBlock(1), (u16*) _data, (_width * _height) / 2);

    /* Main tile background */
    *_BG0_CONTROL_ = 3 |            // priority, 0 is highest, 3 is lowest
        (1 << 2)  |                 // the char block the image data is stored in
        (0 << 6)  |                 // the mosaic flag
        (1 << 7)  |                 // color mode, 0 is 16 colors, 1 is 256 colors
        (1 << 8) |                  // the screen block the tile data is stored in
        (1 << 13) |                 // wrapping flag
        (0 << 14);                  // bg size, 0 is 256x256

    /* Light background */
    *_BG1_CONTROL_ = 1 |            // priority, 0 is highest, 3 is lowest
        (1 << 2)  |                 // the char block the image data is stored in
        (0 << 6)  |                 // the mosaic flag
        (1 << 7)  |                 // color mode, 0 is 16 colors, 1 is 256 colors
        (2 << 8) |                  // the screen block the tile data is stored in
        (1 << 13) |                 // wrapping flag
        (0 << 14);                  // bg size, 0 is 256x256
    
    *_BG2_CONTROL_ = 0 |            // priority, 0 is highest, 3 is lowest
        (1 << 2)  |                 // the char block the image data is stored in
        (0 << 6)  |                 // the mosaic flag
        (1 << 7)  |                 // color mode, 0 is 16 colors, 1 is 256 colors
        (3 << 8) |                  // the screen block the tile data is stored in
        (1 << 13) |                 // wrapping flag
        (0 << 14);                  // bg size, 0 is 256x256
   
    /* Game ui background */
    *_BG3_CONTROL_ = 0 |            // priority, 0 is highest, 3 is lowest
        (1 << 2)  |                 // the char block the image data is stored in
        (0 << 6)  |                 // the mosaic flag
        (1 << 7)  |                 // color mode, 0 is 16 colors, 1 is 256 colors
        (0 << 8)  |                 // the screen block the tile data is stored in
        (1 << 13) |                 // wrapping flag
        (0 << 14);                  // bg size, 0 is 256x256
}
 