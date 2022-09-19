#ifndef TIME_H
#define TIME_H

#include "u.h"
#include "../../defines.h"

typedef struct
{
    u8 seconds;
    u8 minutes;
    u8 hours;
} time;

u64 tick = 0;

void addTick()
{
    tick += UPDATES_PER_SECOND;
}

time getTime()
{
    time time;
    time.seconds = tick / UPDATES_PER_SECOND;

    if (time.seconds > 59)
    {
        time.minutes = time.seconds / 60;
        time.seconds -= time.minutes * 60;
    }

    if (time.minutes > 59)
    {
        time.hours = time.minutes / 60;
        time.minutes -= time.hours * 60;
    }

    return time;
}

#endif
