/**
 * Timer
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains all defenitions needed to work with Timers
*/

#ifndef _TIMER_H_
#define _TIMER_H_

#include "utils/types.h"

/* Pointer to GBA timer 0 DATA and CONTROL registry */
#define _TIMER_0_DATA_      ((vu16*) 0x4000100)
#define _TIMER_0_CONTROL_   ((vu16*) 0x4000102)

/* Pointer to GBA timer 1 DATA and CONTROL registry */
#define _TIMER_1_DATA_      ((vu16*) 0x4000104)
#define _TIMER_1_CONTROL_   ((vu16*) 0x4000106)

/* Pointer to GBA timer 2 DATA and CONTROL registry */
#define _TIMER_2_DATA_      ((vu16*) 0x4000108)
#define _TIMER_2_CONTROL_   ((vu16*) 0x400010A)

#define _TIMER_3_DATA_      ((vu16*) 0x400010C)
#define _TIMER_3_CONTROL_   ((vu16*) 0x400010E)

/* Different constants for frequencies of different timer modes */
#define _TIMER_FREQ_1_    0x0
#define _TIMER_FREQ_64_   0x1
#define _TIMER_FREQ_256_  0x2
#define _TIMER_FREQ_1024_ 0x3

/* Clock constant */
#define _CLOCK_             16777216 

/* CPU cycles per one screen blank */
#define _CYCLES_PER_BLANK_  280806

/* Constants for overflowing GBA timer  */
#define _TIMER_CASCADE_     0x4
#define _TIMER_INTERRUPTION 0x40
#define _TIMER_ENABLE_      0x80

/* Macro used for getting global time */
#define _GET_GLOBAL_TIME_ *_TIMER_3_DATA_

/* Structure that contains timestamps of the start and stop of the timer */
typedef struct Timer {
    /* Timestamp of the timer start */
    i32 startTimestamp;
    
    /* Timestamp of the timer stop */
    i32 stopTimestamp;
} Timer;

/**
 * Initializes global GBA timer
*/
inline void counterInit();

/**
 * Starts global GBA timer
*/
inline void counterStart();

/**
 * Stops global GBA timer
*/
inline void counterStop();

/**
 * Initializes Timer structure
 * 
 * @param _timer Pointer to Timer structure
*/
void initTimer(Timer *_timer);

/**
 * Starts timer
 * 
 * @param _timer Pointer to Timer structure
*/
void startTimer(Timer *_timer);

/**
 * Stops timer
 * 
 * @param _timer Pointer to Timer structure
*/
void stopTimer(Timer *_timer);

/**
 * Returns formated time from provided timer
 * 
 * @param _timer Pointer to Timer structure
 * @return Vector where X, Y, Z are hour, minutes and second respectivly
*/
ivec3 formatTime(Timer *_timer);

#endif
