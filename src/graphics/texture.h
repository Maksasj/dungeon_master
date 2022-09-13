#ifndef TEXTURE_H
#define TEXTURE_H

#include "../defines.h"
#include "../gbastd/graphics.h"
#include "../gbastd/types/u.h"
#include "../gbastd/types/vector.h"

#include "../../assets/generated/jojo.h"

typedef struct {
    u16 width;
    u16 height;
    u16* data;
} texture;

texture* loadTextureFromArray(const u16 data[], u16 width, u16 height) {
    texture tex;
    tex.width = width;
    tex.height = height;
    //tex.data = data;

    tex.data = (u16*)malloc(width*height*sizeof(u16));
    int i; int j;
    for(i = 0; i < width; i++) {
        for(j = 0; j < height; j++) {
            tex.data[i*width + j] = data[i*width + j];
        }
    }
    

    texture* texPtr = &tex;
    return texPtr; 
}

void drawTexture(u16* VBUFFER, texture* tex, ivec2 pos) {
    int i; int j;
    for(i = 0; i < tex->width; i++) {
        if(i + pos.x > SW) { continue; }
        for(j = 0; j < tex->height; j++) {
            if(j + pos.y > SH) { continue; }
            VBUFFER[(pos.y + j)*GBA_SW + i + pos.x] = tex->data[i*80 + j];
        }
    }
}

#endif
