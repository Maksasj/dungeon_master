#include "include/sprite.h"

Sprite* spriteInit(Sprite _sprites[], i32* _next_sprite_index, i32 _x, i32 _y, SpriteSize _size, i32 _horizontal_flip, i32 _vertical_flip, i32 _tile_index, i32 _priority) {

    i32 index = *_next_sprite_index;
    ++(*_next_sprite_index);

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

    _sprites[index].attribute0 = _y |               /* y coordinate */
                            (0 << 8) |              /* rendering mode */
                            (0 << 10) |             /* gfx mode */
                            (0 << 12) |             /* mosaic */
                            (1 << 13) |             /* color mode, 0:16, 1:256 */
                            (shape_bits << 14);     /* shape */

    _sprites[index].attribute1 = _x |               /* x coordinate */
                            (0 << 9) |              /* affine flag */
                            (h << 12) |             /* horizontal flip flag */
                            (v << 13) |             /* vertical flip flag */
                            (size_bits << 14);      /* size */

    _sprites[index].attribute2 = _tile_index |      /* tile index */
                            (_priority << 10) |     /* priority */
                            (0 << 12);              /* palette bank (only 16 color)*/

    return &_sprites[index];
}

void spriteSetOffset(Sprite* _sprite, i32 _offset) {
    _sprite->attribute2 &= 0xfc00;

    _sprite->attribute2 |= (_offset & 0x03ff);
}

void spriteSetHorizontalFlip(Sprite* _sprite, i32 _horizontal_flip) {
    if (_horizontal_flip) {
        _sprite->attribute1 |= 0x1000;
    } else {
        _sprite->attribute1 &= 0xefff;
    }
}

void spriteSetVerticalFlip(Sprite* _sprite, i32 _vertical_flip) {
    if (_vertical_flip) {
        _sprite->attribute1 |= 0x2000;
    } else {
        _sprite->attribute1 &= 0xdfff;
    }
}

void spriteMove(Sprite* _sprite, i32 _dx, i32 _dy) {
    i32 y = _sprite->attribute0 & 0xff;
    i32 x = _sprite->attribute1 & 0x1ff;

    spritePosition(_sprite, x + _dx, y + _dy);
}

void spritePosition(Sprite* _sprite, i32 _x, i32 _y) {
    _sprite->attribute0 &= 0xff00;
    _sprite->attribute0 |= (_y & 0xff);
    _sprite->attribute1 &= 0xfe00;
    _sprite->attribute1 |= (_x & 0x1ff);
}

void spriteUpdateAll(Sprite* _sprites) {
    memcpy16DMA(_SPRITE_ATTRIBUTE_MEMORY_, (u16*) _sprites, _NUM_SPRITES_ * 4);
}

void spriteClear(Sprite* _sprites, i32* _next_sprite_index) {
    (*_next_sprite_index) = 0;

    i32 i;
    for(i = 0; i < _NUM_SPRITES_; i++) {
        _sprites[i].attribute0 = _SCREEN_HEIGHT_;
        _sprites[i].attribute1 = _SCREEN_WIDTH_;
    }
}

ivec2 getSpriteWidthAndLength(SpriteSize _sprite_size_in_pixels) {
    ivec2 size = newIVec2(2, 2);

    switch (_sprite_size_in_pixels)
    {
        case SIZE_8_8:   size.x <<= 2; size.y <<= 2; break;
        case SIZE_16_16: size.x <<= 3; size.y <<= 3; break;
        case SIZE_32_32: size.x <<= 4; size.y <<= 4; break;
        case SIZE_64_64: size.x <<= 5; size.y <<= 5; break;
        case SIZE_16_8:  size.x <<= 3; size.y <<= 2; break;
        case SIZE_32_8:  size.x <<= 4; size.y <<= 2; break;
        case SIZE_32_16: size.x <<= 4; size.y <<= 3; break;
        case SIZE_64_32: size.x <<= 5; size.y <<= 4; break;
        case SIZE_8_16:  size.x <<= 2; size.y <<= 3; break;
        case SIZE_8_32:  size.x <<= 2; size.y <<= 4; break;
        case SIZE_16_32: size.x <<= 3; size.y <<= 4; break;
        case SIZE_32_64: size.x <<= 4; size.y <<= 5; break;
    }

    return size;
}
