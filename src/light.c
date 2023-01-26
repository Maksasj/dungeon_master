#include "../include/light.h"

inline void setLightLayer(i32 light) {
    vu16* layer = LIGHT_BACKGROUND_SCREEN_BLOCK;
    setScreenBlock(layer, (u16) light);
}