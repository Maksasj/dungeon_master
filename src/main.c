#include "input.h"
#include "gameLogic.h"
#include "graphicsEngine.h"

int main() {

    initGraphicsEngine();

    while(1) {
        input();
        gameLogic();
        graphicsEngine();
    }

    return 0;
}
