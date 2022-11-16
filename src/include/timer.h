#ifndef _TIMER_H_
#define _TIMER_H_

#include "types.h"

/* define the timer control registers */
#define _TIMER_0_DATA_    ((vu16*) 0x4000100)
#define _TIMER_0_CONTROL_ ((vu16*) 0x4000102)

/* make defines for the bit positions of the control register */
#define _TIMER_FREQ_1_    0x0
#define _TIMER_FREQ_64_   0x2
#define _TIMER_FREQ_256_  0x3
#define _TIMER_FREQ_1024_ 0x4
#define _TIMER_ENABLE_    0x80

/* the GBA clock speed is fixed at this rate */
#define _CLOCK_ 16777216 
#define _CYCLES_PER_BLANK_ 280806

#endif