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

u8 worldCollision(World *world, ivec2 pos) {
    return collisionCallBack(&world->rooms[world->activeRoom], pos);
}

u8 doorCollision(World *world, ivec2 pos) {
    if(pos.x < 112 || pos.x > 128) return 0;
    if(pos.y < 0 || pos.y > 16) return 0;

    return 1;
}
