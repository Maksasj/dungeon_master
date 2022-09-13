#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "gameState/gameState.h"

void gameLogic(gameState* game) {
    if(game->activeScene == SPLASH_SCENE) {
        //If during splash screen was pressed any button, game imideatly goes to Main menu scene
        if(ifAnyButtonPressed(game->buttons) == TRUE) {
            game->activeScene = MAIN_MENU_SCENE;
        }
    } else if(game->activeScene == MAIN_MENU_SCENE) {
        //game logic as if it a main menu
    } else if (game->activeScene == GAME_SCENE) {
        //game logic as if it a main game
    }
}

#endif
