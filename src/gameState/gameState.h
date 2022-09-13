#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../gameScenes/gameScenes.h"
#include "buttonState.h"

typedef struct {
    scene activeScene;
    buttonState buttons;

    //Variable for testing
    u64 timer;
} gameState; 

#endif
