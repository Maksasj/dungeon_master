#include "include/interruption.h"

void interruptionInit(void (*ptr)()) {
    /* create custom interrupt handler for vblank - whole point is to turn off sound at right time
     * we disable interrupts while changing them, to avoid breaking things */
    *_INTERRUPT_ENABLE_ = 0;
    *_INTERRUPT_CALLBACK_ = (u32) &(*ptr);
    *_INTERRUPT_SELECTION_ |= _INT_VBLANK_;
    *_DISPLAY_INTERRUPTS_ |= 0x08;
    *_INTERRUPT_ENABLE_ = 1;
}
