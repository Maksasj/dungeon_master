#ifndef _ROOM_MACROS_H_
#define _ROOM_MACROS_H_

#include "prototypes/floor_beginning_room.h"
#include "prototypes/two_ninja_skeleton_room.h"
    
static void (*ROOM_PROTOTYPES_INIT_CALLBACKS[])(Room*) = {
    &floorBeginningRoomInit,
    &twoNinjaSkeletonRoomInit
};

static void (*ROOM_PROTOTYPES_RENDER_CALLBACKS[])(Room*, void*) = {
    &floorBeginningRoomRender,
    &twoNinjaSkeletonRoomRender
};

static void (*ROOM_PROTOTYPES_UPDATE_CALLBACKS[])(Room*, Entity*) = {
    &floorBeginningRoomUpdateCallback,
    &twoNinjaSkeletonRoomUpdateCallback
};

#endif
