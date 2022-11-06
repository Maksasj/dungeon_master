#ifndef SPRITE_H
#define SPRITE_H

#include "defines.h"

/* palette is always 256 colors */
#define PALETTE_SIZE 256

/* there are 128 sprites on the GBA */
#define NUM_SPRITES 128

struct Sprite {
    unsigned short attribute0;
    unsigned short attribute1;
    unsigned short attribute2;
    unsigned short attribute3;
};

enum SpriteSize {
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
};

struct Sprite* sprite_init(
    struct Sprite sprites[],
    int* next_sprite_index,

    int x, int y, enum SpriteSize size,
    int horizontal_flip, int vertical_flip, int tile_index, int priority);

void sprite_set_offset(struct Sprite* sprite, int offset);

void sprite_set_horizontal_flip(struct Sprite* sprite, int horizontal_flip);

void sprite_set_vertical_flip(struct Sprite* sprite, int vertical_flip);

void sprite_move(struct Sprite* sprite, int dx, int dy);

void sprite_position(struct Sprite* sprite, int x, int y);

void sprite_update_all(struct Sprite* sprites);

void sprite_clear(struct Sprite* sprites, int* next_sprite_index);

#endif
