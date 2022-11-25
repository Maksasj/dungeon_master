#include "include/grid.h"

const i32 DIRECTION_VECTORS[4][2] = {
    {0, 1},  //Up
    {1, 0},  //Right
    {0, -1}, //Down
    {-1, 0}  //Left
};

const i8 DIRECTION[4] = {
    'd', //Down
    'l', //Left
    'u', //Up
    'r'  //Right
};

SquareGrid* gridInit() {
    SquareGrid* grid;

    i32 i;
    i32 j;
    for (i = 0; i < _ROOM_LENGTH_; ++i) {
        for (j = 0; j < _ROOM_WIDTH_; ++j) {
            grid->came_from[i][j] = newIVec2(-1, -1);
        }
    }

    return grid;
}

i32 inBounds(ivec2 _coordinates) {
    return 0 <= _coordinates.x && _coordinates.x < _ROOM_WIDTH_
        && 0 <= _coordinates.y && _coordinates.y < _ROOM_LENGTH_;
}

i32 passable(SquareGrid* _grid, ivec2 _coordinates) {
    //TODO: Detect obstacles
    return 1;
}

ivec2* getNeighbors(SquareGrid* _grid, ivec2* neighbors, ivec2 _coordinates) {
    ivec2 next;

    i32 i;
    for (i = 0; i < _AMOUNT_OF_NEIGHBORS_; ++i) {
        next = newIVec2(_coordinates.x + DIRECTION_VECTORS[i][0], _coordinates.y + DIRECTION_VECTORS[i][1]);
        
        if (inBounds(next) && passable(_grid, next)) {
            neighbors[i] = next;
        }
    }

    return neighbors;
}

void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position) {
    ivec2Queue* queue = createQueue();
    ivec2* neighbors = (ivec2*)malloc(_AMOUNT_OF_NEIGHBORS_ * sizeof(ivec2));

    push(queue, _start_position);

    while (!empty(queue)) {
        ivec2 current = pop(queue);

        neighbors = getNeighbors(_grid, neighbors, current);

        i32 index;
        for (index = 0; index < _AMOUNT_OF_NEIGHBORS_; ++index) {
            ivec2 next = neighbors[index];

            if (_grid->came_from[next.x][next.y].x == -1 ||
                _grid->came_from[next.x][next.y].y == -1) {
                    
                push(queue, next);
                _grid->came_from[next.x][next.y] = current;

                _grid->vertices[next.x][next.y] = DIRECTION[index];
            }
        }
    }

    free(queue);
    free(neighbors);
}

void clearGrid(SquareGrid* _grid) {
    i32 i;
    i32 j;
    for (i = 0; i < _ROOM_LENGTH_; ++i) {
        for (j = 0; j < _ROOM_WIDTH_; ++j) {
            _grid->came_from[i][j] = newIVec2(-1, -1);
            _grid->vertices[i][j] = ' ';
        }
    }
}
