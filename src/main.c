#include "input.h"
#include "gameLogic.h"
#include "graphicsEngine.h"

#include "gameScenes/gameScenes.h"
#include "gameState/gameState.h"

int main() {
    gameState *game;
    game->activeScene = SPLASH_SCENE;

    initGraphicsEngine();

    int o = 0;

    while(1) {

        buttonState state = input(game, &o);
        gameLogic(game);

        graphicsEngine(game, state);
    }

    return 0;
}
