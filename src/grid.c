#include "include/grid.h"

const i32 DIRECTION_VECTORS[4][2] = {
    {0, 1},  //Up
    {1, 0},  //Right
    {0, -1}, //Down
    {-1, 0}  //Left
};

const char DIRECTION[4] {
    'u', //Up
    'r', //Right
    'd', //Down
    'l'  //Left
};

SquareGrid* gridInit(i32 _width, i32 _height) {
    SquareGrid* grid;
    grid->width = _width;
    grid->height = _height;

    grid->vertices* = malloc(_width * sizeof(i8));
    grid->vertices** = malloc(_height * sizeof(i8));

    return grid;
}

i32 inBounds(SquareGrid* _grid, ivec2 _coordinates) {
    return 0 <= _coordinates.x && _coordinates.x < _grid->width
        && 0 <= _coordinates.y && _coordinates.y < _grid->height;
}

i32 passable(SquareGrid* _grid, ivec2 _coordinates) {
    //TODO: Detect obstacles
    return 1;
}

ivec2* getNeighbors(SquareGrid* _grid, ivec2 _coordinates) {
    ivec2 neighbors[_AMOUNT_OF_NEIGHBORS_];

    ivec2 next;

    i32 i;
    for (i = 0; i < _AMOUNT_OF_NEIGHBORS_; ++i) {
        next = newIVec2(_coordinates.x + DIRECTION_VECTORS[i][0], _coordinates.y + DIRECTION_VECTORS[i][1]);
        
        if (inBounds(_grid, next) && passable(_grid, next)) {
            neighbors[i] = next;
        }
    }

    return neighbors;
}

void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position) {
    ivec2Queue* queue = createQueue();
    push(queue, _start_position);

    while (!empty(queue)) {
        ivec2 current = pop(queue);

        ivec2* neighbors = getNeighbors(_grid, current);
        i32 index;
        for (index = 0; index < _AMOUNT_OF_NEIGHBORS_; ++index) {
            
        }
    }
}
