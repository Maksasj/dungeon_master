#include "include/world.h"

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index) {
    _world->activeRoom = _roomId;
    renderRoom(&_world->rooms[_roomId], _sprites, _next_sprite_index);
}

void generateWorld(World* _world) {
    u32 i;
    Room first_room;
    first_room.type = BASIC;
    _world->rooms[0] = first_room;

    for(i = 1; i < _MAX_ROOM_COUNT_; ++i) {
        Room room;

        room.type = TWO_ENEMIES;
        _world->rooms[i] = room;
        tryPushEntityToRoom(&_world->rooms[i], entityInit(newFVec2(50.0, 50)));
    }   

    _world->difficulty = 1;
}

CollisionType worldCollision(World* _world, ivec2 _pos) {
    return collisionCallBack(&_world->rooms[_world->activeRoom], _pos);
}
