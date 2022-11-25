#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "types.h"

#define _INITIAL_QUEUE_SIZE_ 40

typedef struct ivec2Queue {
    ivec2 items[_INITIAL_QUEUE_SIZE_];
    i32 front;
    i32 rear;
} ivec2Queue;

ivec2Queue* createQueue();

void push(ivec2Queue* _queue, ivec2 _value);

ivec2 pop(ivec2Queue* _queue);

i32 empty(ivec2Queue* _queue);

void reset(ivec2Queue* _queue);

#endif
