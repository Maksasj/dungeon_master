#include "include/world.h"

void nextRoom(World *world, Sprite* _sprites, i32* _next_sprite_index) {
    int i;
    for(i = 0; i < world->rooms[world->activeRoom].current_entity_count; ++i) {
        Entity *entity = &world->rooms[world->activeRoom].entity_pool[i];
        entityUnloadSprite(entity);
    }

    ++world->activeRoom;
    gotoRoom(world, world->activeRoom, _sprites, _next_sprite_index);
}

void backRoom(World *world, Sprite* _sprites, i32* _next_sprite_index) {
    int i;
    for(i = 0; i < world->rooms[world->activeRoom].current_entity_count; ++i) {
        Entity *entity = &world->rooms[world->activeRoom].entity_pool[i];
        entityUnloadSprite(entity);
    }

    --world->activeRoom;
    gotoRoom(world, world->activeRoom, _sprites, _next_sprite_index);
}

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index) {
    world->activeRoom = roomId;
    renderRoom(_world, &_world->rooms[_roomId], _sprites, _next_sprite_index);
}

void updateWorld(World* world, Entity* player) {
    Room *room = &world->rooms[world->activeRoom];
    
    i32 i;
    for(i = 0; i < room->current_entity_count; ++i) {
        Entity *entity = &room->entity_pool[i];
        (*entity->update_callback)(entity, room);

        entityUpdate(entity);
    }
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
    //Dividing cords by 16
    i32 x = (_pos.x + 8) >> 4;
    i32 y = (_pos.y + 8) >> 4;

    char tile = _world->collision_box[y][x];

    switch (tile) {
        case '#':
            return WALL;
        case 'D':
            return OPENED_DOOR;
        case 'C':
            return CLOSED_DOOR;
        case 'E':
            return ENEMY;
        case 'X':
            return CHEST;
        default:
            return NONE;
    }
    
    return NONE;
}
