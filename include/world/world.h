#ifndef _WORLD_H_
#define _WORLD_H_

#include "../utils/types.h"
#include "../sprite.h"
#include "../utils/queue.h"
#include "../utils/grid.h"
#include "../sound/sound.h"

#include "room.h"

#define _MAX_ROOM_COUNT_ 5
#define _BFS_TICK_RATE_ 50

typedef struct World {
    Room rooms[_MAX_ROOM_COUNT_];

    SquareGrid grid;

    u8 activeRoom;

    u8 floorCount;
    u8 currentFloor;
    
    //TODO
    u8 difficulty;

    u16 MAP[1024];

    /*
        '#' - Wall
        'D' - Opened Door
        'C' - Closed Door
        'E' - Next Floor Entrance
        'X' - Chest
        ' ' - None
    */
    u8 collision_box[10][15];
} World;

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index);

void generateFloor(World* _world);

void worldUpdate(World* _world);

void updateWorld(World* _world, Entity* _player);

void nextRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index);

void backRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index);

CollisionType worldCollision(World* _world, ivec2 _pos);

inline ivec2 screenToGridPosition(fvec2 _screen_position);

#endif
