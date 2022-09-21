#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../gameScenes/gameScenes.h"
#include "buttonState.h"
#include "timer.h"

typedef struct {
    scene activeScene;
    buttonState buttons;
    Timer* timer;
} gameState; 

#endif
