#include "../../include/world/world.h"

#include "../../include/world/room_macros.h"
#include "../../include/entity/entity_macros.h"
#include "../../include/item/item_macros.h"

static void* _SPRITES_POINTER_;
static void* _NEXT_SPRITE_INDEX_;

static u32 WORLD_TICK = 0;

i32 game_completed = 0;
u8 floor_switch = 0;
u8 room_switch = 0;

void nextRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    int new_room = _world->activeRoom + 1;
    gotoRoom(_world, new_room, _sprites, _next_sprite_index);
}

void backRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index) {
    int new_room = _world->activeRoom - 1;
    gotoRoom(_world, new_room, _sprites, _next_sprite_index);
}

void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index) {
    _SPRITES_POINTER_= _sprites;
    _NEXT_SPRITE_INDEX_ = _next_sprite_index;

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

    if (_world->rooms[_roomId].type == END_GAME_ROOM) {
        game_completed = 1;
    }

    _world->activeRoom = _roomId;
    renderRoom(_world, &_world->rooms[_roomId], _sprites, _next_sprite_index);
}

void updateWorldLight(World* _world) {
    Room *room = &_world->rooms[_world->activeRoom];
    vu16* lightLayer = LIGHT_BACKGROUND_SCREEN_BLOCK;

    int i;
    for(i = 0; i < room->current_light_count; ++i) {
        ivec2 light = room->lights[i];
        RENDER_LIGHT_BULB(lightLayer, light.x, light.y);
    }
}

void updateWorld(World* _world, Entity* _player) {
    Room *room = &_world->rooms[_world->activeRoom];

    ROOM_PROTOTYPES_UPDATE_CALLBACKS[room->type](_world, room, _player);

    if(WORLD_TICK % _BFS_TICK_RATE_ == 0) {
        if (room->current_entity_count > 0) {
            ivec2 world_position = screenToWorldPosition(_player->position);
            breadthFirstSearch(&_world->grid, world_position, _world->collision_box);
        }
    }

    i32 i;
    for(i = 0; i < room->current_entity_count; ++i) {
        Entity *entity = &room->entity_pool[i];
        (*entity->update_callback)(entity, _world, room);

        if ((*entity->on_collision_enter)(entity, _player)) {
            if (entity->item_use_cooldown == 0) {
                notePlay(NOTE_BES, 1);

                #ifndef _GOD_MODE_ 
                if (!_player->invulnerable) {
                    if (!(*_player->dodge_callback)(_player)) {
                        entityAttack(entity, _player);
                        makeInvulnerable(_player);
                    }
                }
                #endif

                entity->item_use_cooldown = entity->max_attack_cooldown;
            }
        }

        if (entity->item_use_cooldown > 0) {
            --entity->item_use_cooldown;
        }

        if (entity->health <= 0) {
            deleteEntityFromRoom(entity, room);
        }

        entitySpriteUpdate(entity);
    }
    
    for(i = 0; i < room->current_projectile_count; ++i) {
        Projectile *projectile = &room->projectile_pool[i];
        (*projectile->update_callback)(projectile, _world, room);

        if (projectile->facing == LEFT || projectile->facing == RIGHT) {
            CollisionType xCol = 
                worldCollision(
                    _world,
                    newIVec2(
                        (projectile->position.x >> _POSITION_FIXED_SCALAR_) + projectile->vel.x,
                         projectile->position.y >> _POSITION_FIXED_SCALAR_)
                );
            
            if(xCol != NONE) {
                entityUnloadSprite(projectile);
                deleteProjectileFromRoom(projectile, room);
                --(*((i32*)_NEXT_SPRITE_INDEX_));
                
                break;
            }
        } else {
            CollisionType yCol = 
                worldCollision(
                    _world, 
                    newIVec2(
                        projectile->position.x >> _POSITION_FIXED_SCALAR_,
                        (projectile->position.y >> _POSITION_FIXED_SCALAR_) + projectile->vel.y)
                );
            if(yCol != NONE) {
                entityUnloadSprite(projectile);
                deleteProjectileFromRoom(projectile, room);
                --(*((i32*)_NEXT_SPRITE_INDEX_));
                
                break;
            }
        }
        
        if(projectile->layer == PLAYER) {

            i32 j;
            for(j = 0; j < room->current_entity_count; ++j) { 
                Entity *entity = &room->entity_pool[j];
                
                if (checkCollision(entity, projectile)) {
                    i32 calculated_damage = (*projectile->calculate_damage_callback)(entity);
                    entityTakeDamage(entity, calculated_damage);

                    entityUnloadSprite(projectile);
                    deleteProjectileFromRoom(projectile, room);
                    --(*((i32*)_NEXT_SPRITE_INDEX_));

                    break;
                }
            }

        }

        entitySpriteUpdate(projectile);
    }

    static i32 item_ui_offset = -28;
    i8 is_collision_with_any_item = 0;
    static i32 item_pickup_cooldown = 0;
    PlayerSpecData* pspec = (PlayerSpecData*)_player->spec;

    ++item_pickup_cooldown;
    for(i = 0; i < room->current_itemdrop_count; ++i) {
        ItemDrop *itemdrop = &room->itemdrop_pool[i];

        if (checkCollision(_player, (Entity*) itemdrop)) {
            
            is_collision_with_any_item = 1;

            if(buttonPressed(_BUTTON_B_)) {
                if(item_pickup_cooldown < 200) continue; 
                
                item_pickup_cooldown = 0;
                
                if(itemdrop->item.type == WEAPON) {
                    if(pspec->hand_slot.count != 0) {
                        Item item = pspec->hand_slot;
                        tryPushItemDropToRoom(room, 
                            itemDropInit( 
                                newIVec2(   _player->position.x >> _POSITION_FIXED_SCALAR_, 
                                            _player->position.y >> _POSITION_FIXED_SCALAR_), 
                                item, 
                                item.drop_sprite_offset));
                        loadTmpItemDropSprite(room);
                    }
                } else {
                    if(pspec->armor_slot.count != 0) {
                        Item item = pspec->armor_slot;
                        tryPushItemDropToRoom(room, 
                            itemDropInit( 
                                newIVec2(   _player->position.x >> _POSITION_FIXED_SCALAR_, 
                                            _player->position.y >> _POSITION_FIXED_SCALAR_), 
                                item, 
                                item.drop_sprite_offset));
                        loadTmpItemDropSprite(room);
                    }
                }

                putOnItem(_player, itemdrop->item);
                itemDropUnloadSprite(itemdrop);
                deleteItemDropFromRoom(itemdrop, room);
                updatePlayerSpec(pspec, _player);
                break;
            } else {
                if(WORLD_TICK % 5 == 0) {
                    if(item_ui_offset + 1 <= 0)
                        ++item_ui_offset;
                }
                
                Statblock itemStats = itemdrop->item.base_stats;
                Statblock compareStats;

                if(itemdrop->item.type == WEAPON) {
                    if(pspec->hand_slot.count != 0) {
                        compareStats = pspec->hand_slot.base_stats;
                    } else {
                        compareStats = stats(0, 0, 0, 0, 0);
                    }
                } else {
                    if(pspec->armor_slot.count != 0) {
                        compareStats = pspec->armor_slot.base_stats;
                    } else {
                        compareStats = stats(0, 0, 0, 0, 0);
                    }
                }

                u16* layer = DYNAMIC_UI_BACKGROUND_SCREEN_BLOCK;

                {
                    i32 statDifference = compareStats.stamina - itemStats.stamina;
                    layer[3 + 26 + (5 + 3)*32] = 374 + _ABS_(statDifference);
                    
                    if(statDifference > 0) {
                        layer[2 + 26 + (5 + 3)*32] = 373;
                    } else if(statDifference < 0) {
                        layer[2 + 26 + (5 + 3)*32] = 371;
                    } else {
                        layer[2 + 26 + (5 + 3)*32] = 372;
                    }
                }

                {
                    i32 statDifference = compareStats.agility - itemStats.agility;
                    layer[3 + 26 + (5 + 4)*32] = 374 + _ABS_(statDifference);
                    
                    if(statDifference > 0) {
                        layer[2 + 26 + (5 + 4)*32] = 373;
                    } else if(statDifference < 0) {
                        layer[2 + 26 + (5 + 4)*32] = 371;
                    } else {
                        layer[2 + 26 + (5 + 4)*32] = 372;
                    }
                }

                {
                    i32 statDifference = compareStats.intellect - itemStats.intellect;
                    layer[3 + 26 + (5 + 5)*32] = 374 + _ABS_(statDifference);
                    
                    if(statDifference > 0) {
                        layer[2 + 26 + (5 + 5)*32] = 373;
                    } else if(statDifference < 0) {
                        layer[2 + 26 + (5 + 5)*32] = 371;
                    } else {
                        layer[2 + 26 + (5 + 5)*32] = 372;
                    }
                }

                {
                    i32 statDifference = compareStats.strength - itemStats.strength;
                    layer[3 + 26 + (5 + 6)*32] = 374 + _ABS_(statDifference);
                    
                    if(statDifference > 0) {
                        layer[2 + 26 + (5 + 6)*32] = 373;
                    } else if(statDifference < 0) {
                        layer[2 + 26 + (5 + 6)*32] = 371;
                    } else {
                        layer[2 + 26 + (5 + 6)*32] = 372;
                    }
                }

                {
                    i32 statDifference = compareStats.armor - itemStats.armor;
                    layer[3 + 26 + (5 + 7)*32] = 374 + _ABS_(statDifference);
                    
                    if(statDifference > 0) {
                        layer[2 + 26 + (5 + 7)*32] = 373;
                    } else if(statDifference < 0) {
                        layer[2 + 26 + (5 + 7)*32] = 371;
                    } else {
                        layer[2 + 26 + (5 + 7)*32] = 372;
                    }
                }

                spriteSetOffset(pspec->itemUIIcon, itemdrop->sprite_offset);
                spritePosition(pspec->itemUIIcon, 220 - item_ui_offset, 45);

                (*_BG2_X_SCROLL_) = item_ui_offset;
            }
        }
        entitySpriteUpdate((Entity*) itemdrop);
    }

    if(is_collision_with_any_item == 0) {
        if(WORLD_TICK % 5 == 0) {
            if(item_ui_offset - 1 >= -28)
                --item_ui_offset;
        }

        spritePosition(pspec->itemUIIcon, 220 - item_ui_offset, 45);
        (*_BG2_X_SCROLL_) = item_ui_offset;
    }

    if (_player->item_use_cooldown > 0) {
        --_player->item_use_cooldown;
    }
    
    ++WORLD_TICK;
}

void generateFloor(World* _world, Entity* _player) {
    ROOM_PROTOTYPES_INIT_CALLBACKS[FLOOR_BEGINNING_ROOM](&_world->rooms[0], _player);

    i32 i = 1;
    for(; i < _MAX_ROOM_COUNT_ - 1; ++i) {
        ROOM_PROTOTYPES_INIT_CALLBACKS[_GET_RANDOM_ROOM_WITH_ENEMY_](&_world->rooms[i], _player);
    }

    if(_world->currentFloor == _world->floorCount)
        ROOM_PROTOTYPES_INIT_CALLBACKS[END_GAME_ROOM](&_world->rooms[_MAX_ROOM_COUNT_ - 1], _player);
    else
        ROOM_PROTOTYPES_INIT_CALLBACKS[FLOOR_END_ROOM](&_world->rooms[_MAX_ROOM_COUNT_ - 1], _player);

    _world->grid = gridInit();

    ++_world->currentFloor;
}

CollisionType worldCollision(World* _world, ivec2 _pos) {
    //Dividing cords by 16
    i32 x = (_pos.x + 8) >> 4;
    i32 y = (_pos.y + 8) >> 4;
    
    //log(LOG_INFO, "%d <- %d, %d", _world->collision_box[y][x], y, x);
    
    return _world->collision_box[y][x];
}

inline ivec2 screenToWorldPosition(ivec2 _screen_position) {
    ivec2 grid_position;

    grid_position.x = (((_screen_position.x >> _POSITION_FIXED_SCALAR_) - 8) >> 4);
    grid_position.y = (((_screen_position.y >> _POSITION_FIXED_SCALAR_) - 8) >> 4);

    return grid_position;
}

void placeTile(World* _world, u16* _target, ivec2 _pos, Tile _tile, CollisionType _collision_type) {
    _target[_pos.x * 2 + _pos.y * 2 * 32] = _tile.x[0];
    _target[_pos.x * 2 + _pos.y * 2 * 32 + 1] = _tile.x[1];
    _target[_pos.x * 2 + _pos.y * 2 * 32 + 32] = _tile.x[2];
    _target[_pos.x * 2 + _pos.y * 2 * 32 + 33] = _tile.x[3];

    _world->collision_box[_pos.y][_pos.x] = _collision_type;
}
