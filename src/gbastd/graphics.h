#ifndef GBASTD_GRAPHICS_H
#define GBASTD_GRAPHICS_H

#include "types/u.h"
#include "types/color.h"
#include "types/vector.h"

#include "../defines.h"
#include "gbastd.h"

u16 rgbToHex(rgb color) {
    return (color.r)+((color.g)<<5)+((color.b)<<10);
}

void clearBackground(rgb color) {
    int x; int y;
    
    for(x = 0; x < SW; x++) {
        for(y = 0; y < SH; y++) {
            VRAM[y*GBA_SW+x]=rgbToHex(color);
        }
    }
}

void drawPixel(ivec2 pos, rgb color) {
    VRAM[pos.y*GBA_SW+pos.x]=rgbToHex(color);
}

#endif
