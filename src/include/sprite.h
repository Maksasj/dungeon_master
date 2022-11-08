#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "types.h"
#include "gfx.h"

/* palette is always 256 colors */
#define _PALETTE_SIZE_ 256

/* there are 128 sprites on the GBA */
#define _NUM_SPRITES_ 128

/* the memory location which controls sprite attributes */
#define _SPRITE_ATTRIBUTE_MEMORY_ ((vu16*) 0x7000000)

typedef struct Sprite {
    u16 attribute0;
    u16 attribute1;
    u16 attribute2;
    u16 attribute3;
} Sprite;

typedef enum SpriteSize {
    SIZE_8_8,
    SIZE_16_16,
    SIZE_32_32,
    SIZE_64_64,
    SIZE_16_8,
    SIZE_32_8,
    SIZE_32_16,
    SIZE_64_32,
    SIZE_8_16,
    SIZE_8_32,
    SIZE_16_32,
    SIZE_32_64
} SpriteSize;

Sprite* spriteInit(Sprite _sprites[], i32* _next_sprite_index, i32 _x, i32 _y, SpriteSize _size, i32 _horizontal_flip, i32 _vertical_flip, i32 _tile_index, i32 _priority);

void spriteSetOffset(Sprite* _sprite, i32 _offset);

void spriteSetHorizontalFlip(Sprite* _sprite, i32 _horizontal_flip);

void spriteSetVerticalFlip(Sprite* _sprite, i32 _vertical_flip);

void spriteMove(Sprite* _sprite, i32 _dx, i32 _dy);

void spritePosition(Sprite* _sprite, i32 _x, i32 _y);

void spriteUpdateAll(Sprite* _sprites);

void spriteClear(Sprite* _sprites, i32* _next_sprite_index);

#endif
