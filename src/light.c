#include "../include/light.h"

inline void setLightLayer(i32 light) {
    vu16* layer = screenBlock(27);
    setScreenBlock(layer, (u16) light);
}