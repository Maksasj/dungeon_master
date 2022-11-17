#ifndef _ROOM_H_
#define _ROOM_H_

#include "../types.h"

//Include bounding boxes for all rooms
#include "rooms/basic_room.h"

typedef enum ROOM_TYPE {
    BASIC,
} ROOM_TYPE;

typedef struct Room {
    ROOM_TYPE type;

    /* TODO
    Entity pool
    Projectile pool

    Lock criteria

    Update callback
    */
} Room;

void renderRoom(Room *room);

u8 wallCollisionCallBack(Room *room, ivec2 pos);

u8 doorCollisionCallBack(Room *room, ivec2 pos);

#endif
