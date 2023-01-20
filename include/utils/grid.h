/**
 * grid
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows to create a grid to store information about the game world
*/

#ifndef _GRID_H_
#define _GRID_H_

#include "types.h"
#include "queue.h"
#include <stdlib.h>

// Amount of neighbors for BFS algorithm
#define _AMOUNT_OF_NEIGHBORS_ 4

// Room dimensions
#define _ROOM_LENGTH_ 13
#define _ROOM_WIDTH_ 8

// Grid structure, that holds information about game world
typedef struct SquareGrid {
    // grid cells
    i8 vertices[_ROOM_LENGTH_][_ROOM_WIDTH_];

    // distance to player from each grid cell
    i32 distance_to_player[_ROOM_LENGTH_][_ROOM_WIDTH_];

    // visited grid cells (for BFS algorithm)
    i32 visited[_ROOM_LENGTH_][_ROOM_WIDTH_];
} SquareGrid;

/**
 * Initialize grid
 * 
 * @return   Grid
*/
SquareGrid gridInit();

/**
 * BFS algorithm for setting vertices and distance to player
 * 
 * @param _grid             existing grid
 * @param _start_position   start coordinates (x, y)
 * @param _collision_box    existing collision box for obstacle detection 
*/
void breadthFirstSearch(SquareGrid* _grid, ivec2 _start_position, u8 _collision_box[10][15]);

/**
 * Clears vertices, distances and visited arrays
 * 
 * @param _grid             existing grid
*/
void clearGrid(SquareGrid* _grid);

#endif
