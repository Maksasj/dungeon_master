#include "include/world/path_graph.h"

Graph graphInit() {
    Graph graph;

    i32 i;
    i32 j;
    for (i = 0; i < _ROOM_LENGTH_; ++i) {
        for (j = 0; j < _ROOM_WIDTH_; ++j) {
            graph.vertices[i][j] = 0;
            //TODO: if obstacle, then graph.vertices[i][j] = 1;
        }
    }

    return graph;
}

void breadthFirstSearch(Graph _graph, ivec2 _start_position) {

}