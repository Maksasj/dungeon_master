#include "../include/timer.h"

inline void counterInit() {
    *_TIMER_2_CONTROL_ = 0;
    *_TIMER_3_CONTROL_ = 0;

    *_TIMER_2_DATA_ = -0x4000;
    *_TIMER_3_DATA_ = 0;
}

inline void counterStart() {
    *_TIMER_2_CONTROL_ = _TIMER_FREQ_1024_ | _TIMER_ENABLE_;
    *_TIMER_3_CONTROL_ = _TIMER_ENABLE_ | _TIMER_CASCADE_;
}

inline void counterStop() {
    *_TIMER_2_CONTROL_ = 0;
    *_TIMER_3_CONTROL_ = 0;
}

void initTimer(Timer *timer) {
    timer->startTimestamp   = -1;
    timer->stopTimestamp    = -1;
}

void startTimer(Timer *timer) {
    timer->startTimestamp = *_TIMER_3_DATA_;
}

void stopTimer(Timer *timer) {
    timer->stopTimestamp = *_TIMER_3_DATA_;
}

/*
    x - hours
    y - minutes
    z - seconds
*/

ivec3 formatTime(Timer *timer) {
    if(timer->startTimestamp == -1) return (ivec3){.x = 0, .y = 0, .z = 0};
    
    int tmpStopTimestamp = timer->stopTimestamp;
    if(tmpStopTimestamp == -1) 
        tmpStopTimestamp = *_TIMER_3_DATA_;
    
    i32 delta = tmpStopTimestamp - timer->startTimestamp;

    ivec3 out;

    out.z = delta % 60;
    out.y = (delta / 60) - (delta / 3600)*60;
    out.x = delta / 3600;

    return out;
}