#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H

#include "../types/u.h"

#define FALSE (u8)0
#define TRUE (u8)1

typedef struct {
    u8 A;
    u8 B;
    u8 SELECT;
    u8 START;
    u8 RIGHT;
    u8 LEFT;
    u8 UP;
    u8 DOWN;
    u8 R;
    u8 L;
} buttonState; 

#endif
