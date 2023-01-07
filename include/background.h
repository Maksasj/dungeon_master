/**
 * Background
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains all needed functions and structures needed to work with backgrounds
*/

#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "utils/types.h"
#include "sprite.h"

/* Constant what determines tile map thing */
#define _TILEMAP_               0x6000000

/* Size of the char memory block */
#define _CHAR_BLOCK_SIZE_       0x4000

/* Size of the screen memory block */
#define _SCREEN_BLOCK_SIZE_     0x800

/* Pointer to the main background palette */
#define _BG_PALETTE_ ((vu16*) 0x5000000)

/* Pointer that contains all available background 0 attributes */
#define _BG0_CONTROL_ ((vu16*) 0x4000008)

/* Pointers to offsets of the background 0 */
#define _BG0_X_SCROLL_ ((u16*) 0x4000010)
#define _BG0_Y_SCROLL_ ((u16*) 0x4000012)

/* Pointer that contains all available background 1 attributes */
#define _BG1_CONTROL_ ((vu16*) 0x400000A)

/* Pointers to offsets of the background 1 */
#define _BG1_X_SCROLL_ ((u16*) 0x4000014)
#define _BG1_Y_SCROLL_ ((u16*) 0x4000016)

/**
 * Returns location of block as char block pointer
 * 
 * @param   _block  Index of the block
 * @return          Pointer to char block
*/
vu16* charBlock(u32 _block);

/**
 * Returns location of block as screen block pointer
 * 
 * @param   _block  Index of the block
 * @return          Pointer to screen block
*/
vu16* screenBlock(u32 _block);

/**
 * Function that initializes all backgrounds
*/
void initBackground();

#endif
