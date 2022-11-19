#ifndef _ROOM_H_
#define _ROOM_H_

#include "../types.h"
#include "../collision.h"

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

COLLISION_TYPE collisionCallBack(Room *room, ivec2 pos);

#endif
