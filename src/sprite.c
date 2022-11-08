#include "include/sprite.h"

Sprite* spriteInit(Sprite _sprites[], i32* _next_sprite_index, i32 _x, i32 _y, SpriteSize _size, i32 _horizontal_flip, i32 _vertical_flip, i32 _tile_index, i32 _priority) {

    /* grab the next index */
    i32 index = (*_next_sprite_index)++;

    /* setup the bits used for each shape/size possible */
    i32 size_bits, shape_bits;
    switch (_size) {
        case SIZE_8_8:   size_bits = 0; shape_bits = 0; break;
        case SIZE_16_16: size_bits = 1; shape_bits = 0; break;
        case SIZE_32_32: size_bits = 2; shape_bits = 0; break;
        case SIZE_64_64: size_bits = 3; shape_bits = 0; break;
        case SIZE_16_8:  size_bits = 0; shape_bits = 1; break;
        case SIZE_32_8:  size_bits = 1; shape_bits = 1; break;
        case SIZE_32_16: size_bits = 2; shape_bits = 1; break;
        case SIZE_64_32: size_bits = 3; shape_bits = 1; break;
        case SIZE_8_16:  size_bits = 0; shape_bits = 2; break;
        case SIZE_8_32:  size_bits = 1; shape_bits = 2; break;
        case SIZE_16_32: size_bits = 2; shape_bits = 2; break;
        case SIZE_32_64: size_bits = 3; shape_bits = 2; break;
    }

    i32 h = _horizontal_flip ? 1 : 0;
    i32 v = _vertical_flip ? 1 : 0;

    /* set up the first attribute */
    _sprites[index].attribute0 = _y |             /* y coordinate */
                            (0 << 8) |          /* rendering mode */
                            (0 << 10) |         /* gfx mode */
                            (0 << 12) |         /* mosaic */
                            (1 << 13) |         /* color mode, 0:16, 1:256 */
                            (shape_bits << 14); /* shape */

    /* set up the second attribute */
    _sprites[index].attribute1 = _x |             /* x coordinate */
                            (0 << 9) |          /* affine flag */
                            (h << 12) |         /* horizontal flip flag */
                            (v << 13) |         /* vertical flip flag */
                            (size_bits << 14);  /* size */

    /* setup the second attribute */
    _sprites[index].attribute2 = _tile_index |   // tile index */
                            (_priority << 10) | // priority */
                            (0 << 12);         // palette bank (only 16 color)*/

    /* return pointer to this sprite */
    return &_sprites[index];
}

/* change the tile offset of a sprite */
void spriteSetOffset(Sprite* _sprite, i32 _offset) {
    /* clear the old offset */
    _sprite->attribute2 &= 0xfc00;

    /* apply the new one */
    _sprite->attribute2 |= (_offset & 0x03ff);
}

/* change the vertical flip flag */
void spriteSetHorizontalFlip(Sprite* _sprite, i32 _horizontal_flip) {
    if (_horizontal_flip) {
        /* set the bit */
        _sprite->attribute1 |= 0x1000;
    } else {
        /* clear the bit */
        _sprite->attribute1 &= 0xefff;
    }
}

/* change the vertical flip flag */
void spriteSetVerticalFlip(Sprite* _sprite, i32 _vertical_flip) {
    if (_vertical_flip) {
        /* set the bit */
        _sprite->attribute1 |= 0x2000;
    } else {
        /* clear the bit */
        _sprite->attribute1 &= 0xdfff;
    }
}

/* move a sprite in a direction */
void spriteMove(Sprite* _sprite, i32 _dx, i32 _dy) {
    /* get the current y coordinate */
    i32 y = _sprite->attribute0 & 0xff;

    /* get the current x coordinate */
    i32 x = _sprite->attribute1 & 0x1ff;

    /* move to the new location */
    spritePosition(_sprite, x + _dx, y + _dy);
}

/* set a sprite postion */
void spritePosition(Sprite* _sprite, i32 _x, i32 _y) {
    /* clear out the y coordinate */
    _sprite->attribute0 &= 0xff00;

    /* set the new y coordinate */
    _sprite->attribute0 |= (_y & 0xff);

    /* clear out the x coordinate */
    _sprite->attribute1 &= 0xfe00;

    /* set the new x coordinate */
    _sprite->attribute1 |= (_x & 0x1ff);
}

void spriteUpdateAll(Sprite* _sprites) {
    /* copy them all over */
    memcpy16DMA(_SPRITE_ATTRIBUTE_MEMORY_, (u16*) _sprites, _NUM_SPRITES_ * 4);
}

/* setup all sprites */
void spriteClear(Sprite* _sprites, i32* _next_sprite_index) {
    /* clear the index counter */
    (*_next_sprite_index) = 0;

    /* move all sprites offscreen to hide them */
    i32 i;
    for(i = 0; i < _NUM_SPRITES_; i++) {
        _sprites[i].attribute0 = _SCREEN_HEIGHT_;
        _sprites[i].attribute1 = _SCREEN_WIDTH_;
    }
}