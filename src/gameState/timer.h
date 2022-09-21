#ifndef TIMER_H
#define TIMER_H

#include "../gbastd/types/u.h"
#include "../gbastd/types/time.h"

typedef struct {
    u64 tick;
    u8 is_active_flag;
} Timer;

Timer* initTimer() {
    Timer newTimer;
    Timer* timerPtr = &newTimer;
    return timerPtr;
}

void addTick(Timer* timer) {
        timer->tick++;
}

#endif
