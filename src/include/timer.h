#ifndef _TIMER_H_
#define _TIMER_H_

#include "types.h"

#define _TIMER_0_DATA_      ((vu16*) 0x4000100)
#define _TIMER_0_CONTROL_   ((vu16*) 0x4000102)

#define _TIMER_1_DATA_      ((vu16*) 0x4000104)
#define _TIMER_1_CONTROL_   ((vu16*) 0x4000106)

#define _TIMER_FREQ_1_    0x0
#define _TIMER_FREQ_64_   0x2
#define _TIMER_FREQ_256_  0x3
#define _TIMER_FREQ_1024_ 0x4
#define _TIMER_ENABLE_    0x80

#define _CLOCK_             16777216 
#define _CYCLES_PER_BLANK_  280806

#endif
