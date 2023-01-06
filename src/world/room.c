#include "../../include/world/room.h"
#include "../../include/world/world.h"

#include "../../include/world/tile.h"

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

const u16* getRandomLavaTile() {
    u16 value = rand() % 2;

    switch (value) {
        case 0:
            return LAVA_TILE;
        case 1:
            return LAVA_BIG_TILE;
    }

    return FLOOR_3;
}

void placeTile(World* _world, u16* _target, ivec2 _pos, const u16* _tile, CollisionType _collision_type) {
    _target[_pos.x + _pos.y * 32] = _tile[0];
    _target[_pos.x + _pos.y * 32 + 1] = _tile[1];
    _target[_pos.x + _pos.y * 32 + 32] = _tile[2];
    _target[_pos.x + _pos.y * 32 + 33] = _tile[3];

    switch(_collision_type) {
        case WALL: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = '#';
            break;
        }
        case OPENED_DOOR: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'D';
            break;
        }
        case CLOSED_DOOR: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'C';
            break;
        }
        case CHEST: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'X';
            break;
        }
        case NEXT_FLOOR_ENTRANCE: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'E';
            break;
        }
        default: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = ' ';
            break;
        }
    }
}

void loadBasicRoom(World* _world, u16* _target) {
    i32 i;
    i32 j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(_world, _world->MAP, newIVec2(i*2, j*2), getRandomFloorTile(), NONE);
            //placeTile(_world, _world->MAP, newIVec2(i*2, j*2), SMALL_SPIKES_TILE, NONE);
        }
    }

    for(i = 0; i < 15; ++i) {
        placeTile(_world, _world->MAP, newIVec2(i*2, 18), BORDER_BOTTOM, WALL);
        placeTile(_world, _world->MAP, newIVec2(i*2, 0), BORDER_UP, WALL);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(_world, _world->MAP, newIVec2(28, i*2), BORDER_RIGHT, WALL);
        placeTile(_world, _world->MAP, newIVec2(0, i*2), BORDER_LEFT, WALL);
    }
   
    placeTile(_world, _world->MAP, newIVec2(0, 0), CORNER_LEFT_UP, WALL);
    placeTile(_world, _world->MAP, newIVec2(28, 0), CORNER_RIGHT_UP, WALL);
    placeTile(_world, _world->MAP, newIVec2(0, 18), CORNER_LEFT_BOTTOM, WALL);
    placeTile(_world, _world->MAP, newIVec2(28, 18), CORNER_RIGHT_BOTTOM, WALL);

    //placeTile(_world, _world->MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
}

void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index) {
    loadBasicRoom(_world, (u16*) (((World*) _world)->MAP));

    i32 i;

    switch (_room->type) {
        case BASIC: {
            placeTile(_world, ((World*) _world)->MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
            break;
        }
        case TWO_NINJA_SKELETONS_ENEMIES: {
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 8), BORDER_UP, WALL);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);

                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 8), BORDER_UP, WALL);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 10), BORDER_UP, WALL);

                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 8), BORDER_UP, WALL);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 10), BORDER_UP, WALL);
                break;
            }
        case FOUR_ANCIENT_SKELETONS: {
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

                break;
            }
        case ONE_NINJA_THREE_ANCIENT: {
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

                break;
            }
        case THREE_KINGS: {
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

                break;
            }
        case NECROMANCER_TWO_KINGS: {
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
                placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

                break;
            }
        case FLOOR_END: {
                placeTile(_world, ((World*)_world)->MAP, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);
                placeTile(_world, ((World*)_world)->MAP, newIVec2(14, 8), DOOR_UP_OPENED, NEXT_FLOOR_ENTRANCE);
                break;  
            }
        case END_GAME: {
                placeTile(_world, ((World*)_world)->MAP, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);
                break;
            }
    }

    for(i = 0; i < _room->current_entity_count; ++i) {
        Entity* entity = &_room->entity_pool[i];
        entityInitSprite(entity, _sprites, _next_sprite_index);
        spriteSetOffset(entity->sprite, entity->sprite_offset);
    }

    for(i = 0; i < _room->current_itemdrop_count; ++i) {
        ItemDrop* _itemdrop = &_room->itemdrop_pool[i];

        itemDropInitSprite(_itemdrop, _sprites, _next_sprite_index);
        spriteSetOffset(_itemdrop->sprite, _itemdrop->sprite_offset);
    }

    memcpy16DMA((u16*) screenBlock(31), (u16*) (((World*) _world)->MAP), 32 * 32);
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
    placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
    placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);

    memcpy16DMA((u16*) screenBlock(31), (u16*) (((World*) _world)->MAP), 32 * 32);
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
