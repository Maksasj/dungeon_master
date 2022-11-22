#include "include/world/room.h"
#include "include/world.h"

#include "include/world/tile.h"

#include "assets/map.h"

COLLISION_TYPE collisionCallBack(Room *room, ivec2 pos) {
    //Dividing cords by 16
    i32 x = (pos.x + 8) >> 4;
    i32 y = (pos.y + 8) >> 4;

    char tile = ' ';

    if(room->type == BASIC) {
        tile = BASIC_ROOM_COLLISION_BOX[y][x];
    } else if(room->type == TWO_ENEMIES) {
        tile = BASIC_ROOM_COLLISION_BOX[y][x];
    }

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

void placeTile(u16* target, ivec2 pos, const u16* tile) {
    target[pos.x + pos.y * 32] = tile[0];
    target[pos.x + pos.y * 32 + 1] = tile[1];
    target[pos.x + pos.y * 32 + 32] = tile[2];
    target[pos.x + pos.y * 32 + 33] = tile[3];
}

void loadBasicRoom(u16* target) {
    i32 i; i32 j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(MAP, newIVec2(i*2, j*2), getRandomFloorTile());
        }
    }

    for(i = 0; i < 15; ++i) {
        placeTile(MAP, newIVec2(i*2, 18), BORDER_BOTTOM);
        placeTile(MAP, newIVec2(i*2, 0), BORDER_UP);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(MAP, newIVec2(28, i*2), BORDER_RIGHT);
        placeTile(MAP, newIVec2(0, i*2), BORDER_LEFT);
    }

   
    placeTile(MAP, newIVec2(0, 0), CORNER_LEFT_UP);
    placeTile(MAP, newIVec2(28, 0), CORNER_RIGHT_UP);
    placeTile(MAP, newIVec2(0, 18), CORNER_LEFT_BOTTOM);
    placeTile(MAP, newIVec2(28, 18), CORNER_RIGHT_BOTTOM);


    placeTile(MAP, newIVec2(14, 0), DOOR_UP_OPENED);
    //placeTile(MAP, newIVec2(14, 18), DOO);

    /*
    placeTile(MAP, newIVec2(2, 8), DOOR_UP_CLOSED);
    placeTile(MAP, newIVec2(4, 8), DOOR_UP_OPENED);
    placeTile(MAP, newIVec2(6, 8), DOOR_RIGHT_CLOSED);
    placeTile(MAP, newIVec2(8, 8), DOOR_LEFT_CLOSED);
    placeTile(MAP, newIVec2(10, 8), DOOR_BOTTOM_CLOSED);
    */
}

void renderRoom(Room* _room, Sprite* _sprites, i32* _next_sprite_index) {
    loadBasicRoom(MAP);

    if(_room->type == BASIC) {
    
    } else if (_room->type == TWO_ENEMIES) {
        //init_entities
        //TODO load entities

        placeTile(MAP, newIVec2(14, 0), DOOR_UP_CLOSED);
        placeTile(MAP, newIVec2(14, 18), DOOR_BOTTOM_CLOSED);
        
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
        ++room->current_entity_count;
    }
}
