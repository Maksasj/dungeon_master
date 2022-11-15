#include "include/world.h"

void gotoRoom(World *world, u8 roomId) {
    world->activeRoom = roomId;
    renderRoom(&world->rooms[roomId]);
}

void generateWorld(World *world) {
    int i;
    for(i = 0; i < _MAX_ROOM_COUNT_; ++i) {
        Room room;
        room.type = BASIC;
        world->rooms[i] = room;
    }
}

void worldCollision(World *world, ivec2 pos) {
    collisionCallBack(world->rooms[world->activeRoom], pos);
}
