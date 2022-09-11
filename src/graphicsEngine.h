#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "gbastd/gbastd.h"
#include "gbastd/graphics.h"
#include "types/color.h"

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

void graphicsEngine(gameState* game, buttonState a) {
    if(game->buttons.SELECT == 1) {
        clearBackground(color(0, 255, 0));
    } else {
        clearBackground(color(255, 0, 0));
    }

    drawPixel(vec2I(15, 15), color(255, 0, 0));

    while(*Scanline<160){}

    flipVBuffers();
}

int initGraphicsEngine() {
    //Init mode 5------------------------------------------------------------------
    *(u16*)0x4000000 = 0x405;                                           //mode 5 background 2
    *(u16*)0x400010A = 0x82;                                            //enable timer for fps
    *(u16*)0x400010E = 0x84;                                            //cnt timer overflow

    //scale small mode 5 screen to full screen-------------------------------------
    REG_BG2PA=256/2;                                                    //256=normal 128=scale 
    REG_BG2PD=256/2;   

    return 0;
}

#endif
