#include "input.h"
#include "game_logic.h"
#include "graphics_engine.h"

int main() {
    while(1) {
        input();
        game_logic();
        graphics_engine();
    }

    return 0;
}
