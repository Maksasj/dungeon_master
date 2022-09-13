#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "gbastd/gbastd.h"
#include "gbastd/graphics.h"
#include "gbastd/types/color.h"

#include "defines.h"

void flipVBuffers() {
    if (DISPCNT&BACKB){ 
        DISPCNT &= ~BACKB; 
        VRAM=(u16*)VRAM_B;
    } else { 
        DISPCNT |=  BACKB; 
        VRAM=(u16*)VRAM_F;
    }
}

void graphicsEngine(gameState* game) {
    if(game->activeScene == SPLASH_SCENE) {
        //TODO design graphics pipeline
        clearBackground(color(0, 255, 0));

        drawPixel(vec2I(15, 15), color(255, 0, 0));
    } else if(game->activeScene == MAIN_MENU_SCENE) {
        //TODO design graphics pipeline
        clearBackground(color(255, 0, 0));

        drawPixel(vec2I(15, 15), color(255, 0, 0));
    } else if(game->activeScene == GAME_SCENE) {
        //TODO design graphics pipeline
        clearBackground(color(255, 0, 0));

        drawPixel(vec2I(15, 15), color(255, 0, 0));
    }

    while(*Scanline<160){}
    flipVBuffers();
}

int initGraphicsEngine() {
    *(u16*)0x4000000 = 0x405;
    *(u16*)0x400010A = 0x82;
    *(u16*)0x400010E = 0x84;

    REG_BG2PA=256/2;
    REG_BG2PD=256/2;   

    return 0;
}

#endif
