#ifndef _GRID_H_
#define _GRID_H_

#include "types.h"
#include "queue.h"
#include <stdlib.h>

#define _AMOUNT_OF_NEIGHBORS_ 4
#define _MAX_AMOUNT_OF_OBSTACLES_ 30

typedef struct SquareGrid {
    i32 width;
    i32 height;

    i8 vertices**;
} SquareGrid;

SquareGrid* gridInit(i32 _width, i32 _height);

i32 inBounds(SquareGrid* _grid, ivec2 _coordinates);

i32 passable(SquareGrid* _grid, ivec2 _coordinates);

ivec2* getNeighbors(SquareGrid* _grid, ivec2 _coordinates);

void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position);

#endif
