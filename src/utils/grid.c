#include "../../include/utils/grid.h"

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

SquareGrid gridInit() {
    SquareGrid grid;

    i32 i;
    i32 j;
    for (i = 0; i < _ROOM_LENGTH_; ++i) {
        for (j = 0; j < _ROOM_WIDTH_; ++j) {
            grid.visited[i][j] = 0;
            grid.distance_to_player[i][j] = 0;
            grid.vertices[i][j] = ' ';
        }
    }

    return grid;
}

i32 inBounds(ivec2 _coordinates) {
    return 0 <= _coordinates.x && _coordinates.x < _ROOM_LENGTH_
        && 0 <= _coordinates.y && _coordinates.y < _ROOM_WIDTH_;
}

i32 passable(SquareGrid* _grid, ivec2 _coordinates, u8 _collision_box[10][15]) {
    if (_collision_box[_coordinates.y + 1][_coordinates.x + 1] == '#' || _collision_box[_coordinates.y + 1][_coordinates.x + 1] == 'X') {
        _grid->vertices[_coordinates.x][_coordinates.y] = '#';
        return 0;
    }

    return 1;
}

ivec2* getNeighbors(SquareGrid* _grid, ivec2* neighbors, ivec2 _coordinates, u8 _collision_box[10][15]) {
    ivec2 next;

    i32 i;
    for (i = 0; i < _AMOUNT_OF_NEIGHBORS_; ++i) {
        next = newIVec2(_coordinates.x + DIRECTION_VECTORS[i][0], _coordinates.y + DIRECTION_VECTORS[i][1]);
        
        if (inBounds(next) && passable(_grid, next, _collision_box)) {
            neighbors[i] = next;
        } else {
            neighbors[i] = newIVec2(-1, -1);
        }
    }

    return neighbors;
}

void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position, u8 _collision_box[10][15]) {
    ivec2Queue* queue = createQueue();
    ivec2* neighbors = (ivec2*)malloc(_AMOUNT_OF_NEIGHBORS_ * sizeof(ivec2));

    push(queue, _start_position);

    while (!empty(queue)) {
        ivec2 current = pop(queue);

        neighbors = getNeighbors(_grid, neighbors, current, _collision_box);

        i32 index;
        for (index = 0; index < _AMOUNT_OF_NEIGHBORS_; ++index) {
            if(neighbors[index].x == -1 || neighbors[index].y == -1) {
                continue;
            }

            ivec2 next = neighbors[index];

            if (!_grid->visited[next.x][next.y]) {
                push(queue, next);

                _grid->visited[next.x][next.y] = 1;
                _grid->vertices[next.x][next.y] = DIRECTION[index];
                _grid->distance_to_player[next.x][next.y] = _grid->distance_to_player[current.x][current.y] + 1;
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
            _grid->visited[i][j] = 0;
            _grid->distance_to_player[i][j] = 0;
            _grid->vertices[i][j] = ' ';
        }
    }
}
