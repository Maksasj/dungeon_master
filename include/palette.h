/**
 * Palette
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File used for switching different palettes for background
*/

#ifndef _PALETTE_H_
#define _PALETTE_H_

#include "utils/types.h"
#include "utils/memory.h"
#include "utils/random.h"

#include "background.h"

/* Transition between palettes speed  */
#define TRANSITION_SPEED 500

void setPalette(u16* _target, u16* _palette);

/* Macro that used for smooth transition to black screen (all colors to black) */
#define _SMOOTH_PALETT_TRANSITION_TO_BLACK_                                         \
    {                                                                               \
        int k;                                                                      \
        int o;                                                                      \
        for(k = 0; k < 32; ++k) {                                                   \
            for(o = 0; o < 256; ++o) {                                              \
                _SMOOTH_PALETT_TRANSITION_(_SPRITE_PALETTE_, 0, o);                 \
                _SMOOTH_PALETT_TRANSITION_(_BG_PALETTE_, 0, o);                     \
            }                                                                       \
            waitVBlank();                                                           \
            delay(TRANSITION_SPEED);                                                \
        }                                                                           \
    }                                                                               \

/* Macro that used for smooth transitioning between scenes */
#define _SMOOTH_PALETT_TRANSITION_(PALETTE, TARGET_COLOR, COLOR_INDEX)              \
    {                                                                               \
        u16 color = PALETTE[COLOR_INDEX];                                           \
                                                                                    \
        u8 blue =  (color >> 10);                                                   \
        u8 green = (color >> 5) - (blue << 5);                                      \
        u8 red = (color & 0x1F);                                                    \
                                                                                    \
        u16 colorTarget = TARGET_COLOR;                                             \
                                                                                    \
        u8 blueTarget =  (colorTarget >> 10);                                       \
        u8 greenTarget = (colorTarget >> 5) - (blueTarget << 5);                    \
        u8 redTarget = (colorTarget & 0x1F);                                        \
                                                                                    \
        if(blue < blueTarget)                                                       \
            blue += 1;                                                              \
        if(blue > blueTarget)                                                       \
            blue -= 1;                                                              \
                                                                                    \
        if(green < greenTarget)                                                     \
            green += 1;                                                             \
        if(green > greenTarget)                                                     \
            green -= 1;                                                             \
                                                                                    \
        if(red < redTarget)                                                         \
            red += 1;                                                               \
        if(red > redTarget)                                                         \
            red -= 1;                                                               \
                                                                                    \
        u16 newColor = (red)+((green)<<5)+((blue)<<10);                             \
        PALETTE[COLOR_INDEX] = newColor;                                            \
    }                                                                               \

#endif
