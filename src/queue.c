#include "include/queue.h"
#include <stdlib.h>

i8Queue* createQueue() {
    i8Queue* queue = malloc(sizeof(i8Queue));
    queue->front = -1;
    queue->rear = -1;

    return queue; 
}

void enqueue(i8Queue* _queue, i8 _value) {
    if (_queue->rear == _INITIAL_QUEUE_SIZE_ - 1) {
        return;
    }

    if (_queue->front == -1) {
        _queue->front = 0;
    }

    ++_queue->rear;
    _queue->items[_queue->rear] = _value;
}

i32 empty(i8Queue* _queue) {
    if (_queue->rear == -1) {
        return 1;
    }

    return 0;
}

void reset(i8Queue* _queue) {
    _queue->front = -1;
    _queue->rear = -1;
}

i8 dequeue(i8Queue* _queue) {
    i8 item;
    
    if (empty(_queue)) {
        item = -1;
    } else {
        item = _queue->items[_queue->front];
        ++_queue->front;

        if (_queue->front > _queue->rear) {
            reset(_queue);
        }
    }
}
