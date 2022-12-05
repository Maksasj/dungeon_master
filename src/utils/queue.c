#include "../../include/utils/queue.h"
#include <stdlib.h>

ivec2Queue* createQueue() {
    ivec2Queue* queue = malloc(sizeof(ivec2Queue));
    queue->front = -1;
    queue->rear = -1;

    return queue; 
}

void push(ivec2Queue* _queue, ivec2 _value) {
    if (_queue->rear == _INITIAL_QUEUE_SIZE_ - 1) {
        return;
    }

    if (_queue->front == -1) {
        _queue->front = 0;
    }

    ++_queue->rear;
    _queue->items[_queue->rear] = _value;
}

i32 empty(ivec2Queue* _queue) {
    if (_queue->rear == -1) {
        return 1;
    }

    return 0;
}

void reset(ivec2Queue* _queue) {
    _queue->front = -1;
    _queue->rear = -1;
}

ivec2 pop(ivec2Queue* _queue) {
    ivec2 item;
    
    if (empty(_queue)) {
        item.x = -1;
        item.y = -1;
    } else {
        item = _queue->items[_queue->front];
        ++_queue->front;

        if (_queue->front > _queue->rear) {
            reset(_queue);
        }
    }

    return item;
}
