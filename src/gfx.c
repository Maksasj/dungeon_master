#include "include/gfx.h"

void waitVBlank() {
    while (*_SCANLINE_COUNTER_ < _SCREEN_HEIGHT_);
}
