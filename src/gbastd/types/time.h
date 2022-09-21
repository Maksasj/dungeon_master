#ifndef TIME_H
#define TIME_H

#include "u.h"
#include "../../defines.h"

typedef struct {
    u8 seconds;
    u8 minutes;
    u8 hours;
} time;

time getTime(u64 ticks) {
    time time;
    time.seconds = ticks / UPDATES_PER_SECOND;

    if (time.seconds > 59) {
        time.minutes = time.seconds / 60;
        time.seconds -= time.minutes * 60;
    }

    if (time.minutes > 59) {
        time.hours = time.minutes / 60;
        time.minutes -= time.hours * 60;
    }

    return time;
}

#endif
