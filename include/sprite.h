/**
 * Sprite
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains all defenitions needed to work with GBA sprites
*/

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "utils/types.h"
#include "utils/gfx.h"

/* Constant used to determine amout of the available colors in GBA sprite palette*/
#define _PALETTE_SIZE_ 256

/* Reserved amount of sprites */
#define _RESERVED_SPRITE_AMOUNT_ 3

/* Constant used to determine max amout of the sprites */
#define _NUM_SPRITES_ 128

/* Main pointer to GBA sprite register */
#define _SPRITE_ATTRIBUTE_MEMORY_ ((vu16*) 0x7000000)

/* Enum that determines all possible sizes of the sprite */
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

/* Structure that stores all attributes of the sprite */
typedef struct Sprite {
    u16 attribute0;
    u16 attribute1;
    u16 attribute2;
    u16 attribute3;
} Sprite;

/**
 * Initiliez new sprite in the global sprite array
 * 
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index
 * @param   _x  X cord of the sprite
 * @param   _y  Y cord of the sprite
 * @param   _size  Size of the sprite
 * @param   _horizontal_flip  flag that determines if sprite should be flipped horizontally
 * @param   _vertical_flip  flag that determines if sprite should be flipped vartically
 * @param   _tile_index  Offset of the sprite in global spritesheet
 * @param   _priority  Rendering priority of the sprite
 * @return Pointer to the sprite
*/
Sprite* spriteInit(Sprite _sprites[], i32* _next_sprite_index, i32 _x, i32 _y, SpriteSize _size, i32 _horizontal_flip, i32 _vertical_flip, i32 _tile_index, i32 _priority);

/**
 * Sets offset attribute of the sprite
 * 
 * @param   _sprite  Pointer to sprite
 * @param   _offset  Offset of the sprite in global spritesheet
*/
void spriteSetOffset(Sprite* _sprite, i32 _offset);

/**
 * Sets horizontall flip attribute of the sprite
 * 
 * @param   _sprite  Pointer to sprite
 * @param   _horizontal_flip  flag that determines if sprite should be flipped horizontally
*/
void spriteSetHorizontalFlip(Sprite* _sprite, i32 _horizontal_flip);

/**
 * Sets vertical flip attribute of the sprite
 * 
 * @param   _sprite  Pointer to sprite
 * @param   _vertical_flip  flag that determines if sprite should be flipped vertically
*/
void spriteSetVerticalFlip(Sprite* _sprite, i32 _vertical_flip);

/**
 * Sets position attribute of the sprite
 * 
 * @param   _sprite  Pointer to sprite
 * @param   _x  New x cord value
 * @param   _y  New y cord value
*/
void spritePosition(Sprite* _sprite, i32 _x, i32 _y);

/**
 * Updates all sprites in the global sprite array
 * 
 * @param   _sprites  Pointer to global sprite array
*/
void spriteUpdateAll(Sprite* _sprites);

/**
 * Clears all sprites in global sprite array
 * 
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index
*/
void spriteClear(Sprite* _sprites, i32* _next_sprite_index);

#endif
