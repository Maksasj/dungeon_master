#include "include/world/graph.h"

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    
    graph->adjLists = malloc(_ROOM_LENGTH_ * _ROOM_WIDTH_ * sizeof(Node*));
    graph->visited = malloc(_ROOM_LENGTH_ * _ROOM_WIDTH_ * sizeof(i8));

    i32 index;
    for (index = 0; index < _ROOM_LENGTH_ * _ROOM_WIDTH_; ++index) {
        graph->adjLists[index] = NULL;
        graph->visited[index] = 0;
    }

    return graph;
}

void breadthFirstSearch(Graph _graph, i8 _start) {
    i8Queue* queue = createQueue();


    enqueue(queue, _start);
}
