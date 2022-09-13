#ifndef COLOR_H
#define COLOR_H

#include "u.h"

typedef struct {
    u16 r;
    u16 g;
    u16 b;
} rgb;

typedef struct {
    u16 r;
    u16 g;
    u16 b;
    u16 a;
} rgba;

rgb color(u16 r, u16 g, u16 b) {
    rgb a = {
        (u16)((r/255.0f)*31),
        (u16)((g/255.0f)*31),
        (u16)((b/255.0f)*31)
    };
    return a;
}

#endif
