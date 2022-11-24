#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "types.h"

#define _INITIAL_QUEUE_SIZE_ 40

typedef struct i8Queue {
    i8 items[_INITIAL_QUEUE_SIZE_];
    i8 front;
    i8 rear;
} i8Queue;

i8Queue* createQueue();
void enqueue(i8Queue* _queue, i8 _value);
i8 dequeue(i8Queue* _queue);
i32 empty(i8Queue* _queue);
void reset(i8Queue* _queue);

#endif
