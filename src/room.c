#include "include/world/room.h"
#include "include/world.h"

#include "include/world/tile.h"

#include "assets/map.h"

#include "include/prototypes/skeleton.h"

const u16* getRandomFloorTile() {
    u16 value = rand() % 6;

    switch (value) {
        case 0:
            return FLOOR_1;
        case 1:
            return FLOOR_2;
        case 2:
            return FLOOR_3;
        case 3:
            return FLOOR_4;
        case 4:
            return FLOOR_5;
        case 5:
            return FLOOR_6;
        default:
            break;
    }

    return FLOOR_3;
}

void placeTile(World* world, u16* target, ivec2 pos, const u16* tile, COLLISION_TYPE collision_type) {
    target[pos.x + pos.y * 32] = tile[0];
    target[pos.x + pos.y * 32 + 1] = tile[1];
    target[pos.x + pos.y * 32 + 32] = tile[2];
    target[pos.x + pos.y * 32 + 33] = tile[3];

    if(collision_type == WALL) {
        world->collision_box[pos.y / 2][pos.x / 2] = '#';
    } else if(collision_type == OPENED_DOOR) {
        world->collision_box[pos.y / 2][pos.x / 2] = 'D';
    } else {
        world->collision_box[pos.y / 2][pos.x / 2] = ' ';
    }
}

void loadBasicRoom(World* world, u16* target) {
    i32 i; i32 j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(world, MAP, newIVec2(i*2, j*2), getRandomFloorTile(), NONE);
        }
    }

    for(i = 0; i < 15; ++i) {
        placeTile(world, MAP, newIVec2(i*2, 18), BORDER_BOTTOM, WALL);
        placeTile(world, MAP, newIVec2(i*2, 0), BORDER_UP, WALL);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(world, MAP, newIVec2(28, i*2), BORDER_RIGHT, WALL);
        placeTile(world, MAP, newIVec2(0, i*2), BORDER_LEFT, WALL);
    }

   
    placeTile(world, MAP, newIVec2(0, 0), CORNER_LEFT_UP, WALL);
    placeTile(world, MAP, newIVec2(28, 0), CORNER_RIGHT_UP, WALL);
    placeTile(world, MAP, newIVec2(0, 18), CORNER_LEFT_BOTTOM, WALL);
    placeTile(world, MAP, newIVec2(28, 18), CORNER_RIGHT_BOTTOM, WALL);


    placeTile(world, MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
    //placeTile(MAP, newIVec2(14, 18), DOO);

    /*
    placeTile(MAP, newIVec2(2, 8), DOOR_UP_CLOSED);
    placeTile(MAP, newIVec2(4, 8), DOOR_UP_OPENED);
    placeTile(MAP, newIVec2(6, 8), DOOR_RIGHT_CLOSED);
    placeTile(MAP, newIVec2(8, 8), DOOR_LEFT_CLOSED);
    placeTile(MAP, newIVec2(10, 8), DOOR_BOTTOM_CLOSED);
    */
}

void renderRoom(void* world, Room* _room, Sprite* _sprites, i32* _next_sprite_index) {
    loadBasicRoom(world, MAP);

    if(_room->type == BASIC) {
    
    } else if (_room->type == TWO_ENEMIES) {
        //init_entities
        //TODO load entities

        placeTile(world, MAP, newIVec2(14, 0), DOOR_UP_CLOSED, OPENED_DOOR);
        placeTile(world, MAP, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, OPENED_DOOR);
        
        int i;
        for(i = 0; i < _room->current_entity_count; ++i) {
            Entity* entity = &_room->entity_pool[i];
            entityInitSprite(entity, _sprites, _next_sprite_index);
            spriteSetOffset(entity->sprite, 32);
        }

    } else {
        //For now we have only basic room
        exit();
    }

    memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
}

void tryPushEntityToRoom(Room *room, Entity _entity) {
    if (room->current_entity_count < _MAX_ENTITY_PER_ROOM_) {
        room->entity_pool[room->current_entity_count] = _entity;
        room->entity_pool[room->current_entity_count].update_callback = &skeleton_update;
        ++room->current_entity_count;
    }
}
