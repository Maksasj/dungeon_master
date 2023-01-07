#include "../../include/world/world.h"
#include "../../include/entity/entity_macros.h"

static u32 WORLD_TICK = 0;
i32 game_completed = 0;

void nextRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    int new_room = _world->activeRoom + 1;
    gotoRoom(_world, new_room, _sprites, _next_sprite_index);
}

void backRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    int new_room = _world->activeRoom - 1;
    gotoRoom(_world, new_room, _sprites, _next_sprite_index);
}

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index) {
    clearGrid(&_world->grid);

    int i;    
    for(i = 0; i < _world->rooms[_world->activeRoom].current_entity_count; ++i) {
        Entity *entity = &_world->rooms[_world->activeRoom].entity_pool[i];
        entityUnloadSprite(entity);
    }

    for(i = 0; i < _world->rooms[_world->activeRoom].current_projectile_count; ++i) {
        Entity *projectile = &_world->rooms[_world->activeRoom].projectile_pool[i];
        entityUnloadSprite(projectile);
    }

    for(i = 0; i < _world->rooms[_world->activeRoom].current_itemdrop_count; ++i) {
        ItemDrop *itemDrop = &_world->rooms[_world->activeRoom].itemdrop_pool[i];
        itemDropUnloadSprite(itemDrop);
    }

    if (_world->rooms[_roomId].type == END_GAME) {
        game_completed = 1;
    }

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
                    entityKnockback(_player, entity->facing, 500);
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

    for(i = 0; i < room->current_projectile_count; ++i) {
        Entity *projectile = &room->projectile_pool[i];
        (*projectile->update_callback)(projectile, _world, room);

        CollisionType xCol = worldCollision(_world, newIVec2((projectile->position.x >> POSITION_FIXED_SCALAR) + projectile->vel.x, projectile->position.y >> POSITION_FIXED_SCALAR));
        if(xCol == WALL) {
            entityUnloadSprite(projectile);
            deleteProjectileFromRoom(projectile, room);
            break;
        }

        CollisionType yCol = worldCollision(_world, newIVec2(projectile->position.x >> POSITION_FIXED_SCALAR, (projectile->position.y >> POSITION_FIXED_SCALAR) + projectile->vel.y));
        if(yCol == WALL) {
            entityUnloadSprite(projectile);
            deleteProjectileFromRoom(projectile, room);
            break;
        }

        if (projectile->layer == ENEMY) {
            if (checkCollision(_player, projectile)) {
                notePlay(NOTE_BES, 1);

                if (!(*_player->dodge_callback)(_player)) {
                    entityAttack(projectile, _player);
                    entityKnockback(_player, projectile->facing, 10);

                    entityUnloadSprite(projectile);
                    deleteProjectileFromRoom(projectile, room);
                }
            }
        } else {
            i32 j;
            for(j = 0; j < room->current_entity_count; ++j) { 
                Entity *entity = &room->entity_pool[j];
                
                if (checkCollision(entity, projectile)) {
                    if (!(*entity->dodge_callback)(entity)) {
                        entityKnockback(entity, projectile->facing, 20);
                        entityAttack(projectile, entity);

                        entityUnloadSprite(projectile);
                        deleteProjectileFromRoom(projectile, room);
                        break;
                    }
                }
            }
        }
        entityUpdate(projectile);
    }
    
    #ifdef _LIGHT_ON_
        vu16* lightLayer = screenBlock(13);

        for(i = 0; i < room->current_light_count; ++i) {
            ivec2 light = room->lights[i];
            RENDER_DYNAMIC_LIGHT_BULB(lightLayer, light.x, light.y);
        }
    #endif

    for(i = 0; i < room->current_itemdrop_count; ++i) {
        ItemDrop *itemdrop = &room->itemdrop_pool[i];
        if (checkCollision(_player, (Entity*) itemdrop)) {
            putOnItem(_player, itemdrop->item);
            itemDropUnloadSprite(itemdrop);
            deleteItemDropFromRoom(itemdrop, room);
        }
        entityUpdate((Entity*) itemdrop);
    }

    //Lets open room if entity count == 0
    if(room->current_entity_count == 0) {
        if (room->type != BASIC && room->type != FLOOR_END && room->type != END_GAME) {
            unLockRoom(_world, room);
        }
    }

    if (_player->attack_cooldown > 0) {
        --_player->attack_cooldown;
    }
    
    ++WORLD_TICK;
}

void generateFloor(World* _world, i32 _class) {
    u32 i;
    Room first_room;

    first_room.type = BASIC;
    first_room.current_entity_count = 0;
    first_room.current_itemdrop_count = 0;
    first_room.current_projectile_count = 0;
    first_room.current_light_count = 0;

    _world->rooms[0] = first_room;

    tryPushLightToRoom(&_world->rooms[0], (ivec2){.x = 112, .y = 0});
    tryPushEntityToRoom(&_world->rooms[0], _SKELETON_ANCIENT_ENTITY_(48, 64));

    _world->grid = gridInit();

    ++_world->currentFloor;

    for(i = 1; i < _MAX_ROOM_COUNT_ - 2; ++i) {
        i32 roomId = random() % 15 + 1;
        Room room;
        
        room.type = roomId;
        room.current_entity_count = 0;
        room.current_itemdrop_count = 0;
        room.current_projectile_count = 0;
        room.current_light_count = 0;

        _world->rooms[i] = room;

        switch (roomId) {
            case TWO_NINJA_SKELETONS_ENEMIES: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(32, 96));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(32, 32));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                break;
            }
            case FOUR_ANCIENT_SKELETONS: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(48, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(80, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(144, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(176, 64));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 160, .y = 80});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 64, .y = 80});
                break;
            }
            case LABYRINTH1: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(96, 16));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(112, 64));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(208, 48));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(32, 128));

                switch (_class) {
                    case 0: { //WARRIOR
                        tryPushItemDropToRoom(&_world->rooms[i], _ICE_SWORD_ITEM_DROP_(48, 128));
                        break;
                    }
                    case 1: { //WIZARD
                        tryPushItemDropToRoom(&_world->rooms[i], _FIRE_STAFF_ITEM_DROP_(48, 128));
                        break;
                    }
                    case 2: { //ARCHER
                        tryPushItemDropToRoom(&_world->rooms[i], _AQUA_BOW_ITEM_DROP_(48, 128));
                        break;
                    }
                }

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 192, .y = 32});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 32, .y = 112});
                break;
            }
            case LABYRINTH2: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(80, 16));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(208, 96));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(208, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(16, 64));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(112, 64));

                switch (_class) {
                    case 0: { //WARRIOR
                        tryPushItemDropToRoom(&_world->rooms[i], _IRON_CHESTPLATE_ITEM_DROP_(16, 32));
                        break;
                    }
                    case 1: { //WIZARD
                        tryPushItemDropToRoom(&_world->rooms[i], _PURPLE_MAGE_ARMOR_ITEM_DROP_(16, 32));
                        break;
                    }
                    case 2: { //ARCHER
                        tryPushItemDropToRoom(&_world->rooms[i], _ARCHER_IRON_ARMOR_ITEM_DROP_(16, 32));
                        break;
                    }
                }
                
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 80});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 208, .y = 80});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 16, .y = 64});
                break;
            }
            case LABYRINTH3: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(192, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(80, 64));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(48, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(160, 64));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(16, 80));

                switch (_class) {
                    case 0: { //WARRIOR
                        tryPushItemDropToRoom(&_world->rooms[i], _ICE_SWORD_ITEM_DROP_(80, 16));
                        tryPushItemDropToRoom(&_world->rooms[i], _GOLDEN_CHESTPLATE_ITEM_DROP_(160, 16));
                        break;
                    }
                    case 1: { //WIZARD
                        tryPushItemDropToRoom(&_world->rooms[i], _FIRE_STAFF_ITEM_DROP_(80, 16));
                        tryPushItemDropToRoom(&_world->rooms[i], _RED_MAGE_ARMOR_ITEM_DROP_(160, 16));
                        break;
                    }
                    case 2: { //ARCHER
                        tryPushItemDropToRoom(&_world->rooms[i], _AQUA_BOW_ITEM_DROP_(80, 16));
                        tryPushItemDropToRoom(&_world->rooms[i], _ARCHER_GOLDEN_ARMOR_ITEM_DROP_(160, 16));
                        break;
                    }
                }

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 16, .y = 128});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 208, .y = 112});
                break;
            }
            case DARK_LABYRINTH: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(16, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(160, 16));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(192, 112));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                break;
            }
            case ANCIENT: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(64, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(208, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(144, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(16, 64));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                break;
            }
            case DUMBBELL: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(96, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(128, 48));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(16, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(208, 64));

                switch (_class) {
                    case 0: { //WARRIOR
                        tryPushItemDropToRoom(&_world->rooms[i], _SHORT_SWORD_ITEM_DROP_(112, 48));
                        break;
                    }
                    case 1: { //WIZARD
                        tryPushItemDropToRoom(&_world->rooms[i], _GEM_STAFF_ITEM_DROP_(112, 48));
                        break;
                    }
                    case 2: { //ARCHER
                        tryPushItemDropToRoom(&_world->rooms[i], _WOODEN_BOW_ITEM_DROP_(112, 48));
                        break;
                    }
                }

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 32, .y = 48});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 192, .y = 48});
                break;
            }
            case SYMMETRIC1: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(64, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(144, 48));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(16, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(208, 64));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 192, .y = 80});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 32, .y = 64});
                break;
            }
            case SYMMETRIC2: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(16, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(176, 32));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(112, 48));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                break;
            }
            case CORRIDORS: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(64, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(160, 64));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(32, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(192, 64));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 48, .y = 32});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 176, .y = 32});
                break;
            }
            case KING_IN_CORRIDOR: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(80, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(144, 48));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(16, 48));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(208, 48));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_KING_ENTITY_(112, 16));

                switch (_class) {
                    case 0: { //WARRIOR
                        tryPushItemDropToRoom(&_world->rooms[i], _SHORT_SWORD_ITEM_DROP_(48, 16));
                        tryPushItemDropToRoom(&_world->rooms[i], _IRON_CHESTPLATE_ITEM_DROP_(176, 16));
                        break;
                    }
                    case 1: { //WIZARD
                        tryPushItemDropToRoom(&_world->rooms[i], _GEM_STAFF_ITEM_DROP_(48, 16));
                        tryPushItemDropToRoom(&_world->rooms[i], _PURPLE_MAGE_ARMOR_ITEM_DROP_(176, 16));
                        break;
                    }
                    case 2: { //ARCHER
                        tryPushItemDropToRoom(&_world->rooms[i], _WOODEN_BOW_ITEM_DROP_(48, 16));
                        tryPushItemDropToRoom(&_world->rooms[i], _ARCHER_IRON_ARMOR_ITEM_DROP_(176, 16));
                        break;
                    }
                }

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 80, .y = 80});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 144, .y = 80});
                break;
            }
            case PAC_MAN: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(16, 80));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(208, 80));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(96, 80));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(112, 80));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(128, 80));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 48, .y = 112});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 176, .y = 112});
                break;
            }
            case PYRAMID: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(64, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(160, 64));

                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(112, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(16, 64));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_NINJA_ENTITY_(208, 64));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 64, .y = 80});
                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 160, .y = 80});
                break;
            }
            case SPIKE_MADNESS: {
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(48, 32));
                tryPushEntityToRoom(&_world->rooms[i], _SKELETON_ANCIENT_ENTITY_(176, 48));

                tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 112, .y = 0});
                break;
            }
            default:
                break;
        }
    }

    Room boss_room;
    boss_room.type = BOSS;
    _world->rooms[_MAX_ROOM_COUNT_ - 2] = boss_room;
    tryPushEntityToRoom(&_world->rooms[_MAX_ROOM_COUNT_ - 2], _NECROMANCER_ENTITY_(112, 64));
    tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 64, .y = 64});
    tryPushLightToRoom(&_world->rooms[i], (ivec2){.x = 176, .y = 64});
    
    Room last_room;

    if (_world->currentFloor != _world->floorCount) {
        last_room.type = FLOOR_END;
    } else {
        last_room.type = END_GAME;
    }
    
    _world->rooms[_MAX_ROOM_COUNT_ - 1] = last_room;
    tryPushLightToRoom(&_world->rooms[_MAX_ROOM_COUNT_ - 1], (ivec2){.x = 112, .y = 64});

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
            return NEXT_FLOOR_ENTRANCE;
        case 'X':
            return TRAP;
        default:
            return NONE;
    }
    
    return NONE;
}

inline ivec2 screenToGridPosition(ivec2 _screen_position) {
    ivec2 grid_position;

    grid_position.x = (((_screen_position.x >> POSITION_FIXED_SCALAR) - 8) >> 4);
    grid_position.y = (((_screen_position.y >> POSITION_FIXED_SCALAR) - 8) >> 4);

    return grid_position;
}
