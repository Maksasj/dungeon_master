#include "include/gfx.h"

/* wait for the screen to be fully drawn so we can do something during vblank */
void waitVBlank() {
    /* wait until all 160 lines have been updated */
    while (*_SCANLINE_COUNTER_ < _SCREEN_HEIGHT_);
}
