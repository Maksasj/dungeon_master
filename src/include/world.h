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

    /*
        '#' - Wall
        'D' - Opened Door
        'C' - Closed Door
        'E' - Enemy
        'X' - Chest
        ' ' - None
    */
    u8 collision_box[10][15];
} World;

void gotoRoom(World *world, u8 roomId, Sprite* _sprites, i32* _next_sprite_index);

void generateWorld(World *world);

void worldUpdate(World *world);

void updateWorld(World* world, Entity* player);

void nextRoom(World *world, Sprite* _sprites, i32* _next_sprite_index);

void backRoom(World *world, Sprite* _sprites, i32* _next_sprite_index);

COLLISION_TYPE worldCollision(World *world, ivec2 pos);

#endif
