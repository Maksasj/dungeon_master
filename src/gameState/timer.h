#ifndef TIMER_H
#define TIMER_H

#include "../gbastd/types/u.h"
#include "../gbastd/types/time.h"

typedef struct {
    u64 tick;
    u8 is_active_flag;
} timer;

timer* initTimer() {
    timer newTimer;
    timer* timerPtr = &newTimer;
    return timerPtr;
}

void addTick(timer* timer) {
        timer->tick++;
}

#endif
