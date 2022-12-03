#include "include/world/room.h"
#include "include/world.h"

#include "include/world/tile.h"

#include "assets/map.h"

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

void placeTile(World* _world, u16* _target, ivec2 _pos, const u16* _tile, CollisionType _collision_type) {
    _target[_pos.x + _pos.y * 32] = _tile[0];
    _target[_pos.x + _pos.y * 32 + 1] = _tile[1];
    _target[_pos.x + _pos.y * 32 + 32] = _tile[2];
    _target[_pos.x + _pos.y * 32 + 33] = _tile[3];

    if(_collision_type == WALL) {
        _world->collision_box[_pos.y / 2][_pos.x / 2] = '#';
    } else if(_collision_type == OPENED_DOOR) {
        _world->collision_box[_pos.y / 2][_pos.x / 2] = 'D';
    } else if(_collision_type == CLOSED_DOOR) {
        _world->collision_box[_pos.y / 2][_pos.x / 2] = 'C';
    } else if(_collision_type == CHEST) {
        _world->collision_box[_pos.y / 2][_pos.x / 2] = 'X';
    }  else {
        _world->collision_box[_pos.y / 2][_pos.x / 2] = ' ';
    }
}

void loadBasicRoom(World* _world, u16* _target) {
    i32 i; i32 j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(_world, MAP, newIVec2(i*2, j*2), getRandomFloorTile(), NONE);
        }
    }

    for(i = 0; i < 15; ++i) {
        placeTile(_world, MAP, newIVec2(i*2, 18), BORDER_BOTTOM, WALL);
        placeTile(_world, MAP, newIVec2(i*2, 0), BORDER_UP, WALL);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(_world, MAP, newIVec2(28, i*2), BORDER_RIGHT, WALL);
        placeTile(_world, MAP, newIVec2(0, i*2), BORDER_LEFT, WALL);
    }

   
    placeTile(_world, MAP, newIVec2(0, 0), CORNER_LEFT_UP, WALL);
    placeTile(_world, MAP, newIVec2(28, 0), CORNER_RIGHT_UP, WALL);
    placeTile(_world, MAP, newIVec2(0, 18), CORNER_LEFT_BOTTOM, WALL);
    placeTile(_world, MAP, newIVec2(28, 18), CORNER_RIGHT_BOTTOM, WALL);


    placeTile(_world, MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);

    /*
    placeTile(MAP, newIVec2(2, 8), DOOR_UP_CLOSED);
    placeTile(MAP, newIVec2(4, 8), DOOR_UP_OPENED);
    placeTile(MAP, newIVec2(6, 8), DOOR_RIGHT_CLOSED);
    placeTile(MAP, newIVec2(8, 8), DOOR_LEFT_CLOSED);
    placeTile(MAP, newIVec2(10, 8), DOOR_BOTTOM_CLOSED);
    */
}

void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index) {
    loadBasicRoom(_world, MAP);

    if(_room->type == BASIC) {
    
    } else if (_room->type == TWO_ENEMIES) {
        //init_entities
        //TODO load entities

        placeTile(_world, MAP, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
        placeTile(_world, MAP, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);
        
        int i;
        for(i = 0; i < _room->current_entity_count; ++i) {
            Entity* entity = &_room->entity_pool[i];
            entityInitSprite(entity, _sprites, _next_sprite_index);
            spriteSetOffset(entity->sprite, entity->sprite_offset); //96 - necromncer
        }

        for(i = 0; i < _room->current_itemdrop_count; ++i) {
            ItemDrop* _itemdrop = &_room->itemdrop_pool[i];

            itemDropInitSprite(_itemdrop, _sprites, _next_sprite_index);
            spriteSetOffset(_itemdrop->sprite, _itemdrop->sprite_offset); //96 - necromncer


            /*
    
            96 - Necromncer

            112 - Iron armor front
            120 - Iron armor back
            128 - Iron armor side

            136 - Golden armor front
            144 - Golden armor back
            152 - Golden armor side

            160 - Diamoand armor front
            168 - Diamoand armor back
            176 - Diamoand armor side

            256 - Short sword icon
            264 - Dark claymore icon
            272 - Ice sword icon

            280 - Iron armor icon
            288 - Golden armor icon
            296 - DIamond armor icon

            184 - Short sword front
            192 - Short sword back
            208 - Short sword side
        
            208 - Claymore front
            216 - Claymore back
            224 - Claymore side

            232 - Ice sword front
            240 - Ice sword back
            248 - Ice sword side

            304 - Heart gem icon
            312 - Mana bar
            
            */
        }

    } else {
        //For now we have only basic room
        //exit();
    }

    memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
}

void tryPushEntityToRoom(Room* _room, Entity _entity) {
    if (_room->current_entity_count < _MAX_ENTITY_PER_ROOM_) {
        _room->entity_pool[_room->current_entity_count] = _entity;
        ++_room->current_entity_count;
    }
}

void tryPushItemDropToRoom(Room* _room, ItemDrop _itemdrop) {
    if (_room->current_itemdrop_count < _MAX_ITEM_DROP_PER_ROOM_) {
        _room->itemdrop_pool[_room->current_itemdrop_count] = _itemdrop;
        ++_room->current_itemdrop_count;
    }
}

void unLockRoom(void* _world, Room* _room) {
    placeTile(_world, MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
    placeTile(_world, MAP, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);

    memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
}

void deleteEntityFromRoom(Entity* _entity, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_entity_count; ++i) {
        if (_entity == &_room->entity_pool[i]) {
            for (j = i + 1; j < _room->current_entity_count; ++j) {
                _room->entity_pool[i] = _room->entity_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_entity_count;
}


void deleteItemDropFromRoom(ItemDrop* _entity, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_itemdrop_count; ++i) {
        if (_entity == &_room->itemdrop_pool[i]) {
            for (j = i + 1; j < _room->current_itemdrop_count; ++j) {
                _room->itemdrop_pool[i] = _room->itemdrop_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_itemdrop_count;
}
