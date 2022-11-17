#include "include/interruption.h"

void initInterruption(void (*_ptr)()) {
    *_INTERRUPT_ENABLE_ = 0;
    *_INTERRUPT_CALLBACK_ = (i32)&_ptr;
    *_INTERRUPT_SELECTION_ |= _INTERRUPT_VBLANK_;
    *_DISPLAY_INTERRUPTS_ |= 0x08;
    *_INTERRUPT_ENABLE_ = 1;
}
