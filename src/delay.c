#include "include\delay.h"

void delay(unsigned int amount) {
    int i;
    for (i = 0; i < amount * 10; i++);
}
