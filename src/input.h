#ifndef INPUT_H
#define INPUT_H

#include "gameState/gameState.h"
#include "gbastd/gbastd.h"

buttonState input(gameState* game, int* o) {
    buttonState state;
    
    if(KEY_SELECT) {
        state.SELECT = TRUE;
    } else {
        state.SELECT = FALSE;
    }

    game->buttons = state;
    game->buttons.SELECT = FALSE;

    return state;
}

#endif
