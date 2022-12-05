#include "../../include/sound/interruption.h"

void interruptionInit(void (*_ptr)()) {
    *_INTERRUPT_ENABLE_ = 0;
    *_INTERRUPT_CALLBACK_ = (u32) &(*_ptr);
    *_INTERRUPT_SELECTION_ |= _INT_VBLANK_;
    *_DISPLAY_INTERRUPTS_ |= 0x08;
    *_INTERRUPT_ENABLE_ = 1;
}
