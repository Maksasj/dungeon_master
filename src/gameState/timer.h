#ifndef TIMER_H
#define TIMER_H

#define TIMER_DELAY_MS 1000

#include <time.h>
#include <stdio.h>
#include "../gbastd/types/u.h"
#include "../gbastd/types/time.h"

typedef struct {
    time_u8 time;
    u8 is_active_flag;
} timer;

timer* initTimer() {
    timer newTimer;
    timer* timerPtr = &newTimer;
    return timerPtr;
}

void delay(ms) {
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock());
}

int counter(timer* activeTimer) {
    while (activeTimer->is_active_flag) {
        if (activeTimer->time.minutes > 59) {
            activeTimer->time.minutes = 0;
            activeTimer->time.hours++;
        }

        if (activeTimer->time.seconds > 59) {
            activeTimer->time.seconds = 0;
            activeTimer->time.minutes++;
        }

        delay(TIMER_DELAY_MS);
        activeTimer->time.seconds++;
    }
}

void startTimer(timer* timer) {
    timer->is_active_flag = 1;
    counter(timer);
}

void stopTimer(timer* activeTimer) {
    activeTimer->is_active_flag = 0;
}

#endif
