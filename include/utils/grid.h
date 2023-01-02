#ifndef _GRID_H_
#define _GRID_H_

#include "types.h"
#include "queue.h"
#include <stdlib.h>

#define _AMOUNT_OF_NEIGHBORS_ 4
#define _MAX_AMOUNT_OF_OBSTACLES_ 30

#define _ROOM_LENGTH_ 13
#define _ROOM_WIDTH_ 8

typedef struct SquareGrid {
    i8 vertices[_ROOM_LENGTH_][_ROOM_WIDTH_];
    i32 distance_to_player[_ROOM_LENGTH_][_ROOM_WIDTH_];
    i32 visited[_ROOM_LENGTH_][_ROOM_WIDTH_];
} SquareGrid;

SquareGrid gridInit();

i32 inBounds(ivec2 _coordinates);

i32 passable(SquareGrid* _grid, ivec2 _coordinates, u8 _collision_box[10][15]);

ivec2* getNeighbors(SquareGrid* _grid, ivec2* neighbors, ivec2 _coordinates, u8 _collision_box[10][15]);

void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position, u8 _collision_box[10][15]);

void clearGrid(SquareGrid* _grid);

#endif
