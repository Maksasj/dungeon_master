#include "include\delay.h"

void delay(u32 _amount) {
    int i;
    for (i = 0; i < _amount * 10; i++);
}
