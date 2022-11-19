#include "include/world.h"

void gotoRoom(World *world, u8 roomId) {
    world->activeRoom = roomId;
    renderRoom(&world->rooms[roomId]);
}

void generateWorld(World *world) {
    u32 i;
    Room room;
    room.type = BASIC;
    world->rooms[0] = room;

    for(i = 1; i < _MAX_ROOM_COUNT_; ++i) {
        room.type = TWO_ENEMIES;
        world->rooms[i] = room;
    }

    world->difficulty = 1;
}

COLLISION_TYPE worldCollision(World *world, ivec2 pos) {
    return collisionCallBack(&world->rooms[world->activeRoom], pos);
}
