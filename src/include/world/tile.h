#ifndef _TILE_H_
#define _TILE_H_

#include "../types.h"

/*===========CORNERS===========*/
const u16 CORNER_LEFT_UP[] = {
    0x0001, 0x0002,
    0x0021, 0x0022,
};

const u16 CORNER_RIGHT_UP[] = {
    0x0005, 0x0006,
    0x0025, 0x0026,
};

const u16 CORNER_LEFT_BOTTOM[] = {
    0x0081, 0x0082,
    0x00a1, 0x00a2,
};

const u16 CORNER_RIGHT_BOTTOM[] = {
    0x0085, 0x0086,
    0x00a5, 0x00a6,
};
/*=============================*/

/*=========WALL BORDERS========*/
const u16 BORDER_UP[] = {
    0x0003, 0x0004,
    0x0023, 0x0024,
};

const u16 BORDER_LEFT[] = {
    0x0041, 0x0042,
    0x0061, 0x0062,
};

const u16 BORDER_RIGHT[] = {
    0x0045, 0x0046,
    0x0065, 0x0066,
};

const u16 BORDER_BOTTOM[] = {
    0x0083, 0x0084,
    0x00a3, 0x00a4,
};
/*=============================*/

const u16 FLOOR_1[] = {
    0x0007, 0x0008,
    0x0027, 0x0028,
};

const u16 FLOOR_2[] = {
    0x0009, 0x000a,
    0x0029, 0x002a,
};

const u16 FLOOR_3[] = {
    0x000b, 0x000c,
    0x002b, 0x002c,
};

const u16 FLOOR_4[] = {
    0x0047, 0x0048,
    0x0067, 0x0068,
};

const u16 FLOOR_5[] = {
    0x0049, 0x004a,
    0x0069, 0x006a,
};

const u16 FLOOR_6[] = {
    0x004b, 0x004c,
    0x006b, 0x006c,
};

#endif
