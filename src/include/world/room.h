#ifndef _ROOM_H_
#define _ROOM_H_

#include "../types.h"
#include "../collision.h"
#include "../entity/entity.h"

//Include bounding boxes for all rooms
#include "rooms/basic_room.h"

#define _MAX_ENTITY_PER_ROOM_ 5

typedef enum RoomType {
    BASIC,
    TWO_ENEMIES
} RoomType;

typedef struct Room {
    RoomType type;

    Entity entity_pool[_MAX_ENTITY_PER_ROOM_];

    i32 current_entity_count;

    /* TODO
    Entity pool
    Projectile pool

    Lock criteria

    Update callback
    */
} Room;

void renderRoom(Room* _room, Sprite* _sprites, i32* _next_sprite_index);

void tryPushEntityToRoom(Room* _room, Entity _entity);

CollisionType collisionCallBack(Room* _room, ivec2 _pos);

#endif
