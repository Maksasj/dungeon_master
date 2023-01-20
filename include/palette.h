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

/* Transition between palettes speed for scenes */
#define _TRANSITION_SPEED_ 500

/* Transition between palettes for rooms  */
#define _ROOM_TRANSITION_SPEED_ 300

void setPalette(u16* _target, u16* _palette);

void fillPalette(u16* _target, u16 _color);

/* Macro that used for smooth transition to black screen (all colors to black) */
#define _SMOOTH_PALETTE_TRANSITION_TO_BLACK_                                        \
    {                                                                               \
        i32 k;                                                                      \
        i32 o;                                                                      \
        for(k = 0; k < 32; ++k) {                                                   \
            for(o = 0; o < 256; ++o) {                                              \
                _SMOOTH_PALETTE_TRANSITION_(_SPRITE_PALETTE_, 0, o);                \
                _SMOOTH_PALETTE_TRANSITION_(_BG_PALETTE_, 0, o);                    \
            }                                                                       \
            waitVBlank();                                                           \
            delay(_TRANSITION_SPEED_);                                              \
        }                                                                           \
    }                                                                               \

#define _MAKE_TRANSITION_(sprite_palette, background_palette, transition_speed)         \
    {                                                                                   \
        i32 k;                                                                          \
        i32 o;                                                                          \
        for(k = 0; k < 32; ++k) {                                                       \
            for(o = 0; o < 256; ++o) {                                                  \
                _SMOOTH_PALETTE_TRANSITION_(_SPRITE_PALETTE_, sprite_palette[o], o);    \
                _SMOOTH_PALETTE_TRANSITION_(_BG_PALETTE_, background_palette[o], o);    \
            }                                                                           \
            waitVBlank();                                                               \
            delay(transition_speed);                                                    \
        }                                                                               \
    }                                                                                   \

/* Macro that used for smooth transitioning between scenes */
#define _SMOOTH_PALETTE_TRANSITION_(PALETTE, TARGET_COLOR, COLOR_INDEX)             \
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
