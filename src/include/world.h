#ifndef _WORLD_H_
#define _WORLD_H_

#include "types.h"
#include "sprite.h"

#include "world/room.h"

#define _MAX_ROOM_COUNT_ 5

typedef struct World {
    Room rooms[_MAX_ROOM_COUNT_];

    u8 activeRoom;
} World;

void gotoRoom(World *world, u8 roomId);

void generateWorld(World *world);

void worldUpdate(World *world);

u8 worldCollision(World *world, ivec2 pos);

#endif
