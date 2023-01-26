#ifndef _ROOM_MACROS_H_
#define _ROOM_MACROS_H_

#include "prototypes/floor_beginning_room.h"
    
static void (*ROOM_PROTOTYPES_INIT_CALLBACKS[])(Room*) = {
    &FloorBeginningRoomInit
};

static void (*ROOM_PROTOTYPES_RENDER_CALLBACKS[])(Room*, void*) = {
    &FloorBeginningRoomRender
};

static void (*ROOM_PROTOTYPES_UPDATE_CALLBACKS[])(Room*, Entity*) = {
    &FloorBeginningRoomUpdateCallback
};

#endif
