#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../gameScenes/gameScenes.h"
#include "buttonState.h"

typedef struct {
    scene activeScene;
    buttonState buttons;
} gameState; 

#endif
