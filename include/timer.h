#ifndef _TIMER_H_
#define _TIMER_H_

#include "utils/types.h"

#define _TIMER_0_DATA_      ((vu16*) 0x4000100)
#define _TIMER_0_CONTROL_   ((vu16*) 0x4000102)

#define _TIMER_1_DATA_      ((vu16*) 0x4000104)
#define _TIMER_1_CONTROL_   ((vu16*) 0x4000106)

#define _TIMER_2_DATA_      ((vu16*) 0x4000108)
#define _TIMER_2_CONTROL_   ((vu16*) 0x400010A)

#define _TIMER_3_DATA_      ((vu16*) 0x400010C)
#define _TIMER_3_CONTROL_   ((vu16*) 0x400010E)

#define _TIMER_FREQ_1_    0x0
#define _TIMER_FREQ_64_   0x1
#define _TIMER_FREQ_256_  0x2
#define _TIMER_FREQ_1024_ 0x3

#define _CLOCK_             16777216 
#define _CYCLES_PER_BLANK_  280806

#define _TIMER_CASCADE_     0x4
#define _TIMER_INTERRUPTION 0x40
#define _TIMER_ENABLE_      0x80

inline void counterInit();
inline void counterStart();
inline void counterStop();

#define GET_GLOBAL_TIME *_TIMER_3_DATA_

typedef struct Timer {
    i32 startTimestamp;
    i32 stopTimestamp;
} Timer;

void initTimer(Timer *timer);

void startTimer(Timer *timer);

void stopTimer(Timer *timer);

ivec3 formatTime(Timer *timer);

#endif
