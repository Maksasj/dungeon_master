#include "input.h"
#include "gameLogic.h"
#include "graphicsEngine.h"

#include "gameScenes/gameScenes.h"
#include "gameState/gameState.h"
#include "gameState/timer.h"

gameState* initGameState() {
    gameState game;
    game.activeScene = SPLASH_SCENE;
    game.timer = initTimer();
    gameState* gamePtr = &game;

    return gamePtr;
}

int main() {
    gameState* game = initGameState();
    initGraphicsEngine();

    while(1) {
        input(game);
        gameLogic(game);
        graphicsEngine(game);
    }

    return 0;
}
