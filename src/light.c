#include "../include/light.h"

inline void setLightLayer(i32 light) {
    vu16* layer = screenBlock(2);
    setScreenBlock(layer, (u16) light);
}