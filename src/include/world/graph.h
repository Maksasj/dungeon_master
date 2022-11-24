#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "../types.h"
#include "../queue.h"
#include "node.h"

#define _MAX_NEIGHBORS_AMOUNT_ 4
#define _ROOM_LENGTH_ 14
#define _ROOM_WIDTH_ 9

typedef struct Graph
{
    i8 vertices[_ROOM_LENGTH_][_ROOM_WIDTH_];
    Node** adjLists;
    i8* visited;
} Graph;

Graph* createGraph();
void breadthFirstSearch(Graph _graph, i8 _start);

#endif
