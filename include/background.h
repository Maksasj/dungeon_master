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
#include "utils/memory.h"
#include "sprite.h"

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

/* Pointer that contains all available background 2 attributes */
#define _BG2_CONTROL_ ((vu16*) 0x400000C)

/* Pointers to offsets of the background 2 */
#define _BG2_X_SCROLL_ ((u16*) 0x4000018)
#define _BG2_Y_SCROLL_ ((u16*) 0x400001A)

/* Pointer that contains all available background 3 attributes */
#define _BG3_CONTROL_ ((vu16*) 0x400000E)

/* Pointers to offsets of the background 3 */
#define _BG3_X_SCROLL_ ((u16*) 0x400001C)
#define _BG3_Y_SCROLL_ ((u16*) 0x400001E)

/**
 * Function that initializes all backgrounds
 * 
 * @param   _pallete  Pointer to target background palette
 * @param   _data  Pointer to target background data
 * @param   _width  Pointer to target background width
 * @param   _height  Pointer to target background height
*/
void initBackground(u16* _pallete, u16* _data, i32 _width, i32 _height);

#endif
