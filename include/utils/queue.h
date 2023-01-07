/**
 * queue
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Queue FIFO
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "types.h"

// Queue start size
#define _INITIAL_QUEUE_SIZE_ 150

// Vector2 structure which contains all coordinates in FIFO array
typedef struct ivec2Queue {
    // Vector2 array
    ivec2 items[_INITIAL_QUEUE_SIZE_];

    // queue front element
    i32 front;

    // queue rear element
    i32 rear;
} ivec2Queue;

/**
 * Creates queue
 * 
 * @return Vector2 queue
*/
ivec2Queue* createQueue();

/**
 * Moves the item to an existing queue
 * 
 * @param _queue    existing queue
 * @param _value    coordinates
*/
void push(ivec2Queue* _queue, ivec2 _value);

/**
 * Pops front item
 * 
 * @param _queue    existing queue
 * 
 * @return front's item coordinates
*/
ivec2 pop(ivec2Queue* _queue);

/**
 * Function that checks if existing queue is empty
 * 
 * @param _queue    existing queue
 * 
 * @return 0 - false, 1 - true
*/
i32 empty(ivec2Queue* _queue);

/**
 * Queue reset
 * 
 * @param _queue    existing queue
*/
void reset(ivec2Queue* _queue);

#endif
