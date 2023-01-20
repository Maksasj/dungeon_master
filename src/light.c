#include "../include/light.h"

inline void setLightLayer(i32 light) {
    vu16* layer = screenBlock(2);
    setScreenBlock(layer, (u16) light);
}

void reloadLight() {
    vu16* pointer = screenBlock(2);
    i32 x;
    i32 y;
    
    for(x = 0; x < 30; ++x) {
        for(y = 0; y < 20; ++y) {
            pointer[x + 32*y] = 0x17;
        }
    }
}
