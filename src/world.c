#include "include/world.h"

static u32 WORLD_TICK = 0;

void nextRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    int i;
    for(i = 0; i < _world->rooms[_world->activeRoom].current_entity_count; ++i) {
        Entity *entity = &_world->rooms[_world->activeRoom].entity_pool[i];
        entityUnloadSprite(entity);
    }

    ++_world->activeRoom;
    gotoRoom(_world, _world->activeRoom, _sprites, _next_sprite_index);
}

void backRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    int i;
    for(i = 0; i < _world->rooms[_world->activeRoom].current_entity_count; ++i) {
        Entity *entity = &_world->rooms[_world->activeRoom].entity_pool[i];
        entityUnloadSprite(entity);
    }

    --_world->activeRoom;
    gotoRoom(_world, _world->activeRoom, _sprites, _next_sprite_index);
}

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index) {
    _world->activeRoom = _roomId;
    renderRoom(_world, &_world->rooms[_roomId], _sprites, _next_sprite_index);
}

void updateWorld(World* _world, Entity* _player) {
    Room *room = &_world->rooms[_world->activeRoom];

    if (WORLD_TICK % _BFS_TICK_RATE_ == 0) {
        if (room->current_entity_count > 0) {
            ivec2 world_position = screenToGridPosition(_player->position);

            clearGrid(&_world->grid);
            breadthFirstSearch(&_world->grid, world_position);
        }
    }

    i32 i;
    for(i = 0; i < room->current_entity_count; ++i) {
        Entity *entity = &room->entity_pool[i];
        (*entity->update_callback)(entity, _world, room);

        if ((*entity->on_collision_enter)(entity, _player)) {
            notePlay(NOTE_BES, 1);
            killEntity(entity);
            deleteEntityFromRoom(entity, room);
        }

        entityUpdate(entity);
    }

    //Lets open room if entity count == 0
    if(room->current_entity_count == 0) {
        if (room->type == TWO_ENEMIES) {
            unLockRoom(_world, room);
        }
    }
    
    ++WORLD_TICK;
}

void generateWorld(World* _world) {
    u32 i;
    Room first_room;

    first_room.type = BASIC;
    _world->rooms[0] = first_room;

    _world->grid = gridInit();

    for(i = 1; i < _MAX_ROOM_COUNT_; ++i) {
        Room room;
        room.type = TWO_ENEMIES;
        _world->rooms[i] = room;
        tryPushEntityToRoom(&_world->rooms[i], entityInit(newFVec2(32.0, 32.0), 1));
        tryPushEntityToRoom(&_world->rooms[i], entityInit(newFVec2(96.0, 32.0), 1));
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

inline ivec2 screenToGridPosition(fvec2 _screen_position) {
    ivec2 fixed_screen_position;
    ivec2 grid_position;

    grid_position.x = ((i32)_screen_position.x >> 4) - 1;
    grid_position.y = ((i32)_screen_position.y >> 4) - 1;

    return grid_position;
}
