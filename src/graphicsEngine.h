#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "./texture.h"
#include "gbastd/gbastd.h"
#include "gbastd/graphics.h"
#include "gbastd/types/color.h"

#include "../assets/generated/jotaro.h"
#include "graphics/texture.h"

#include "defines.h"

texture *jojo;

void flipVBuffers() {
  if (DISPCNT & BACKB) {
    DISPCNT &= ~BACKB;
    VRAM = (u16 *)VRAM_B;
  } else {
    DISPCNT |= BACKB;
    VRAM = (u16 *)VRAM_F;
  }
}

void graphicsEngine(gameState *game) {
  if (game->activeScene == SPLASH_SCENE) {
    // drawPixel(vec2I(15, 15), color(255, 0, 0));
  } else if (game->activeScene == MAIN_MENU_SCENE) {
    // clearBackground(color(255, 0, 0));
    // drawPixel(vec2I(15, 15), color(255, 0, 0));
  } else if (game->activeScene == GAME_SCENE) {
    // clearBackground(color(255, 0, 0));
    // drawPixel(vec2I(15, 15), color(255, 0, 0));
  }

  while (*Scanline < 160) {
  }
  flipVBuffers();
}

int initGraphicsEngine() {
  *(u16 *)0x4000000 = 0x405;
  *(u16 *)0x400010A = 0x82;
  *(u16 *)0x400010E = 0x84;

  REG_BG2PA = 256 / 2;
  REG_BG2PD = 256 / 2;

  jojo = loadTextureFromArray(jotaro, 80, 80);

  return 0;
}

#endif
