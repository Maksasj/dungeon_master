#ifndef _WORLD_H_
#define _WORLD_H_

#include "types.h"
#include "sprite.h"

#include "world/room.h"

#define _MAX_ROOM_COUNT_ 5

typedef struct World {
    Room rooms[_MAX_ROOM_COUNT_];

    u8 activeRoom;
    
    //TODO
    u8 difficulty;
} World;

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index);

void generateWorld(World* _world);

void worldUpdate(World* _world);

CollisionType worldCollision(World* _world, ivec2 _pos);

#endif
