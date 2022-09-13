#ifndef INPUT_H
#define INPUT_H

#include "gameState/gameState.h"
#include "gbastd/gbastd.h"

void input(gameState* game) {
    if(KEY_A) {
        game->buttons.A = TRUE;
    } else {
        game->buttons.A = FALSE;
    }
    if(KEY_B) {
        game->buttons.B = TRUE;
    } else {
        game->buttons.B = FALSE;
    }

    if(KEY_SELECT) {
        game->buttons.SELECT = TRUE;
    } else {
        game->buttons.SELECT = FALSE;
    }
    if(KEY_START) {
        game->buttons.START = TRUE;
    } else {
        game->buttons.START = FALSE;
    }

    if(KEY_RIGHT) {
        game->buttons.RIGHT = TRUE;
    } else {
        game->buttons.RIGHT = FALSE;
    }
    if(KEY_LEFT) {
        game->buttons.LEFT = TRUE;
    } else {
        game->buttons.LEFT = FALSE;
    }
    if(KEY_UP) {
        game->buttons.UP = TRUE;
    } else {
        game->buttons.UP = FALSE;
    }
    if(KEY_DOWN) {
        game->buttons.DOWN = TRUE;
    } else {
        game->buttons.DOWN = FALSE;
    }

    if(KEY_RIGHT_SHIFT) {
        game->buttons.R = TRUE;
    } else {
        game->buttons.R = FALSE;
    }
    if(KEY_LEFT_SHIFT) {
        game->buttons.L = TRUE;
    } else {
        game->buttons.L = FALSE;
    }
}

#endif
