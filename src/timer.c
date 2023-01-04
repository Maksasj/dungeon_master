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
