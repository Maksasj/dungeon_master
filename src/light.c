#include "../include/light.h"

void setLightLayer(i32 light) {
    vu16* layer = screenBlock(13);

    int x;
    int y;
    for(x = 0; x < 30; ++x) {
        for(y = 0; y < 20; ++y) {
            layer[x + 32*y] = light;
        }
    }
}