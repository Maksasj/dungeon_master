/**
 * Tile
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains all constant definitions for all tiles
*/

#ifndef _TILE_H_
#define _TILE_H_

#include "../utils/types.h"

typedef struct Tile { u16 x[4]; } Tile; 

/*===========CORNERS===========*/
#define CORNER_LEFT_UP                  (Tile){0x0001, 0x0002,0x0021, 0x0022}
#define CORNER_RIGHT_UP                 (Tile){0x0005, 0x0006,0x0025, 0x0026}
#define CORNER_LEFT_BOTTOM              (Tile){0x0081, 0x0082,0x00a1, 0x00a2}
#define CORNER_RIGHT_BOTTOM             (Tile){0x0085, 0x0086,0x00a5, 0x00a6}
/*=============================*/

/*=========WALL BORDERS========*/
#define BORDER_UP                       (Tile){0x0003, 0x0004,0x0023, 0x0024}
#define BORDER_LEFT                     (Tile){0x0041, 0x0042,0x0061, 0x0062}
#define BORDER_RIGHT                    (Tile){0x0045, 0x0046,0x0065, 0x0066}
#define BORDER_BOTTOM                   (Tile){0x0083, 0x0084,0x00a3, 0x00a4}
/*=============================*/

/*==========FLOOR_TILES========*/
#define FLOOR_1                         (Tile){0x0007, 0x0008,0x0027, 0x0028}
#define FLOOR_2                         (Tile){0x0009, 0x000a,0x0029, 0x002a}
#define FLOOR_3                         (Tile){0x000b, 0x000c,0x002b, 0x002c}
#define FLOOR_4                         (Tile){0x0047, 0x0048,0x0067, 0x0068}
#define FLOOR_5                         (Tile){0x0049, 0x004a,0x0069, 0x006a}
#define FLOOR_6                         (Tile){0x004b, 0x004c,0x006b, 0x006c}
/*=============================*/

/*=========DOOR_TILES==========*/
#define DOOR_UP_CLOSED                  (Tile){0x000d, 0x000e,0x002d, 0x002e}
#define DOOR_UP_OPENED                  (Tile){0x004d, 0x004e,0x006d, 0x006e}
#define DOOR_RIGHT_CLOSED               (Tile){0x000f, 0x0010,0x002f, 0x0030}
#define DOOR_LEFT_CLOSED                (Tile){0x0011, 0x0012,0x0031, 0x0032}
#define DOOR_BOTTOM_CLOSED              (Tile){0x0013, 0x0014,0x0033, 0x0034}
#define DOOR_BOTTOM_OPENED              (Tile){0x0053, 0x0054,0x0073, 0x0074}
/*=============================*/

/*=========LAVA_TILES==========*/
#define LAVA_TILE                       (Tile){0x0087, 0x0088,0x00A7, 0x00A8}
#define LAVA_BIG_TILE                   (Tile){0x0089, 0x008A,0x00A9, 0x00AA}
/*=============================*/

/*=========TORCH_TILES=========*/
#define TORCH_TILE                      (Tile){0x008B, 0x008C,0x00AB, 0x00AC}
/*=============================*/

/*=========SPIKE_TILES=========*/
#define BIG_SPIKES_TILE                 (Tile){0x008D, 0x008E,0x00AD, 0x00AE}
#define SMALL_SPIKES_TILE               (Tile){0x008F, 0x0090,0x00AF, 0x00B0}
/*=============================*/

#endif
