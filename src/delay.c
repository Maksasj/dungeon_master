#include "include/delay.h"

void delay(u32 _amount) {
    i32 i;
    for (i = 0; i < _amount * 10; i++);
}
