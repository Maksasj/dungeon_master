#ifndef _PATH_GRAPH_H_
#define _PATH_GRAPH_H_

#include "../types.h"

#define _MAX_NEIGHBORS_AMOUNT_ 4
#define _ROOM_LENGTH_ 14
#define _ROOM_WIDTH_ 9

typedef struct Graph
{
    /*
    0 - epmty tile
    1 - obstacle
    */
    i8 vertices[_ROOM_LENGTH_][_ROOM_WIDTH_];
} Graph;

Graph graphInit();
void breadthFirstSearch(Graph _graph, ivec2 _start_position);

#endif
