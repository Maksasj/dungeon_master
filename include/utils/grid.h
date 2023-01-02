#ifndef _GRID_H_
#define _GRID_H_

#include "types.h"
#include "queue.h"
#include <stdlib.h>
#include "logger.h"

#define _AMOUNT_OF_NEIGHBORS_ 4
#define _MAX_AMOUNT_OF_OBSTACLES_ 30

#define _ROOM_LENGTH_ 13
#define _ROOM_WIDTH_ 8

typedef struct SquareGrid {
    i8 vertices[_ROOM_LENGTH_][_ROOM_WIDTH_];
    i32 distance_to_player[_ROOM_LENGTH_][_ROOM_WIDTH_];
    ivec2 came_from[_ROOM_LENGTH_][_ROOM_WIDTH_];
} SquareGrid;

SquareGrid gridInit();

i32 inBounds(ivec2 _coordinates);

i32 passable(SquareGrid* _grid, ivec2 _coordinates);

ivec2* getNeighbors(SquareGrid* _grid, ivec2* neighbors, ivec2 _coordinates);

void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position);

void clearGrid(SquareGrid* _grid, u8*** _collision_box);

#endif
