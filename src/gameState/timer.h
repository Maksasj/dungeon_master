#ifndef TIMER_H
#define TIMER_H

#include "../gbastd/types/u.h"
#include "../gbastd/types/time.h"

typedef struct
{
    time time;
    u8 is_active_flag;
} timer;

timer *initTimer()
{
    timer newTimer;
    timer *timerPtr = &newTimer;
    return timerPtr;
}

#endif
