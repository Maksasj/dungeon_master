#include "../../include/world/world.h"

#include "../../include/entity/entity_macros.h"

#define _GOD_MODE_

static u32 WORLD_TICK = 0;

void nextRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    clearGrid(&_world->grid);

    int i;
    for(i = 0; i < _world->rooms[_world->activeRoom].current_entity_count; ++i) {
        Entity *entity = &_world->rooms[_world->activeRoom].entity_pool[i];
        entityUnloadSprite(entity);
    }

    for(i = 0; i < _world->rooms[_world->activeRoom].current_itemdrop_count; ++i) {
        ItemDrop *itemDrop = &_world->rooms[_world->activeRoom].itemdrop_pool[i];
        itemDropUnloadSprite(itemDrop);
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

    for(i = 0; i < _world->rooms[_world->activeRoom].current_itemdrop_count; ++i) {
        ItemDrop *itemDrop = &_world->rooms[_world->activeRoom].itemdrop_pool[i];
        itemDropUnloadSprite(itemDrop);
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
            breadthFirstSearch(&_world->grid, world_position, _world->collision_box);
        }
    }

    i32 i;
    for(i = 0; i < room->current_entity_count; ++i) {
        Entity *entity = &room->entity_pool[i];
        (*entity->update_callback)(entity, _world, room);

        if ((*entity->on_collision_enter)(entity, _player)) {
            if (entity->attack_cooldown == 0) {
                notePlay(NOTE_BES, 1);
                
                #ifndef _GOD_MODE_ 
                if (!(*_player->dodge_callback)(_player)) {
                    entityAttack(entity, _player);
                    entityKnockback(_player, entity->facing, 10);
                }
                #endif

                entity->attack_cooldown = entity->max_attack_cooldown;
            }
        }

        if (entity->attack_cooldown > 0) {
            --entity->attack_cooldown;
        }

        if (entity->health <= 0) {
            deleteEntityFromRoom(entity, room);
        }

        entityUpdate(entity);
    }

    for(i = 0; i < room->current_itemdrop_count; ++i) {
        ItemDrop *itemdrop = &room->itemdrop_pool[i];
        if (checkCollision(_player, (Entity*) itemdrop)) {
            putOnItem(_player, itemdrop->item);
            itemDropUnloadSprite(itemdrop);
            deleteItemDropFromRoom(itemdrop, room);
        }
    }

    //Lets open room if entity count == 0
    if(room->current_entity_count == 0) {
        if (room->type != BASIC && room->type != END) {
            unLockRoom(_world, room);
        }
    }

    if (_player->attack_cooldown > 0) {
        --_player->attack_cooldown;
    }
    
    ++WORLD_TICK;
}

void generateWorld(World* _world) {
    u32 i;
    Room first_room;

    first_room.type = BASIC;
    _world->rooms[0] = first_room;

    _world->grid = gridInit();

    for(i = 1; i < _MAX_ROOM_COUNT_ - 1; ++i) {
        //i32 roomId = random(_seed) % 4 + 1;
        i32 roomId = TWO_NINJA_SKELETONS_ENEMIES;

        Room room;
        
        room.type = roomId;
        room.current_entity_count = 0;
        room.current_itemdrop_count = 0;

        _world->rooms[i] = room;

        switch (roomId) {
            case TWO_NINJA_SKELETONS_ENEMIES:
                //tryPushEntityToRoom(&_world->rooms[i], TEST(32.0, 96.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(32.0, 96.0));
                //tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(32.0, 32.0));
                break;
            case FOUR_ANCIENT_SKELETONS:
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(48.0, 64.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(80.0, 48.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(144.0, 48.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(176.0, 64.0));
                break;
            case ONE_NINJA_THREE_ANCIENT:
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(112.0, 64.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(192.0, 16.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(192.0, 32.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(208.0, 32.0));
                tryPushItemDropToRoom(&_world->rooms[i], _IRON_CHESTPLATE_ITEM_DROP_(208.0, 16.0));
                break;
            case THREE_KINGS:
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(48.0, 96.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(112.0, 64.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(176.0, 96.0));
                break;
            case NECROMANCER_TWO_KINGS:
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(80.0, 64.0));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(144.0, 64.0));
                tryPushEntityToRoom(&_world->rooms[i], _NECROMANCER_ENTITY_(160.0, 112.0));
                tryPushItemDropToRoom(&_world->rooms[i], _DARK_CLAYMORE_ITEM_DROP_(112.0, 48.0));
                break;
            
            default:
                break;
        }


        //tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(32.0, 32.0));
        //tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(98.0, 32.0));
        //tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(32.0, 98.0));
        //tryPushEntityToRoom(&_world->rooms[i], _NECROMANCER_ENTITY_(98.0, 98.0));
//
        //tryPushItemDropToRoom(&_world->rooms[i], _SHORT_SWORD_ITEM_DROP_(96.0, 64.0));
        //tryPushItemDropToRoom(&_world->rooms[i], _DARK_CLAYMORE_ITEM_DROP_(120.0, 64.0));
        //tryPushItemDropToRoom(&_world->rooms[i], _ICE_SWORD_ITEM_DROP(140.0, 64.0));
//
        //tryPushItemDropToRoom(&_world->rooms[i], _IRON_CHESTPLATE_ITEM_DROP_(96.0, 32.0));
        //tryPushItemDropToRoom(&_world->rooms[i], _GOLDEN_CHESTPLATE_ITEM_DROP_(120.0, 32.0));
        //tryPushItemDropToRoom(&_world->rooms[i], _DIAMOND_CHESTPLATE_ITEM_DROP_(140.0, 32.0));
    }
    
    Room last_room;
    last_room.type = END;
    _world->rooms[_MAX_ROOM_COUNT_ - 1] = last_room;

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

    grid_position.x = ((i32)_screen_position.x >> 4);
    grid_position.y = ((i32)_screen_position.y >> 4);

    return grid_position;
}
