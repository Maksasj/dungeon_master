#include "../../include/entity/prototypes/player.h"

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index) {
    int i = 0;
    for(i = 0; i < HEALTH_CAP; ++i) {
        _playerUI->health[i] = spriteInit(_sprites, _next_sprite_index, 4 + i*16, 3, SIZE_16_16, 0, 0, 0, 0);
        spriteSetOffset(_playerUI->health[i], 312 + 8);
    }

    //_playerUI->manaBar = spriteInit(_sprites, _next_sprite_index, 4, 20, SIZE_32_16, 0, 0, 0, 0);
    //spriteSetOffset(_playerUI->manaBar, 312);
}

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec, PlayerUI* _ui) {
    _pspec->armor = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
    _pspec->weapon = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);

    spritePosition(_pspec->armor, -64, -64);
    spritePosition(_pspec->weapon, -64, -64);

    _pspec->sprites = _sprites;
    _pspec->next_sprite_index = _next_sprite_index;
    
    _pspec->hand_slot.count = 0;
    _pspec->armor_slot.count = 0;

    _pspec->ui = _ui;

    //spriteSetOffset(_pspec->armor, 144);
    //spriteSetOffset(_pspec->weapon, 200);
}

void putOnItem(Entity *player, Item item) {
    PlayerSpecData* pspec = (PlayerSpecData*) player->spec;

    if(item.type == ARMOR) {
        pspec->armor_slot = item;
        pspec->armor_slot.count = 1;
        spriteSetOffset(pspec->armor, pspec->armor_slot.sprite_offset);
    }

    if(item.type == WEAPON) {
        pspec->hand_slot = item;
        pspec->hand_slot.count = 1;
        spriteSetOffset(pspec->weapon, pspec->hand_slot.sprite_offset);
    }
}

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity) {
    i32 offset_x = 0;
    i8 flip = 0;

    if(_entity->facing == RIGHT) {
        offset_x = 16;
    } else if(_entity->facing == LEFT) {
        offset_x = 16;
        flip = 1;
    } else if(_entity->facing == DOWN) {
        offset_x = 8;
    }

    if(_pspec->hand_slot.count != 0) {
        spritePosition(_pspec->weapon, (i32) _entity->position.x, (i32)_entity->position.y);
        spriteSetOffset(_pspec->weapon, _pspec->hand_slot.sprite_offset + offset_x);
        spriteSetHorizontalFlip(_pspec->weapon, flip);
    }

    if(_pspec->armor_slot.count != 0) {
        spritePosition(_pspec->armor, (i32) _entity->position.x, (i32)_entity->position.y);
        spriteSetOffset(_pspec->armor, _pspec->armor_slot.sprite_offset + offset_x);
        spriteSetHorizontalFlip(_pspec->armor, flip);
    }


    i32 player_max_health =  
        _entity->base_stats.stamina + 
        _pspec->armor_slot.base_stats.stamina + 
        _pspec->hand_slot.base_stats.stamina;

    player_max_health = player_max_health > 6 ? 6 : player_max_health;        

    i32 i;
    for(i = 0; i < HEALTH_CAP; ++i) {
        if(i < player_max_health) {
            if(i < _entity->health) {
                spriteSetOffset(_pspec->ui->health[i], 304);
            } else {
                spriteSetOffset(_pspec->ui->health[i], 312 + 16);
            } 
        } else {
            spriteSetOffset(_pspec->ui->health[i], 312 + 8);
        }
    }
}

void playerAttack(Entity* _player, Room* _active_room) {
    Entity temp = *_player;

    switch (_player->facing)
    {
        case RIGHT:
            temp.position.x += _ATTACK_OFFSET_;
            break;
        case LEFT:
            temp.position.x -= _ATTACK_OFFSET_;
            break;
        case DOWN:
            temp.position.y += _ATTACK_OFFSET_;
            break;
        case UP:
            temp.position.y -= _ATTACK_OFFSET_;
            break;
        default:
            break;
    }

    i32 i;

    for(i = 0; i < _active_room->current_entity_count; ++i) {
        Entity *entity = &_active_room->entity_pool[i];

        if ((*entity->on_collision_enter)(entity, &temp)) {
            if (!(*entity->dodge_callback)(entity)) {
                entityKnockback(entity, _player->facing, 20);
                entityAttack(_player, entity);
            }
        }
    }
}

i32 playerCalculateDamage(Entity* _self) {
    PlayerSpecData* pspec = (PlayerSpecData*)_self->spec;
    Item *hand = &pspec->hand_slot;
    Item *armor = &pspec->armor_slot;

    i32 strenght = _self->base_stats.strength + hand->base_stats.strength + armor->base_stats.strength;

    if (strenght < 0) {
        strenght = 0;
    }

    return 1 + strenght;
}

i32 playerTryDodge(Entity* _self) {
    PlayerSpecData* pspec = (PlayerSpecData*)_self->spec;
    Item *hand = &pspec->hand_slot;
    Item *armor = &pspec->armor_slot;
    
    i32 agility = _self->base_stats.agility + hand->base_stats.agility + armor->base_stats.agility;
    
    if (agility < 0) {
        agility = 0;
    }
    
    u32 random_number = random((u32)_self->position.x * (u32)_self->position.y) % 101;

    if (random_number < _DODGE_CHANCE_FROM_AGILITY_ * agility) {
        return 1;
    }

    return 0;
}

void killPlayer(Entity* _self) {
    //TODO: restart the game
    return;
}

void player_update(Entity* _self, World* _world, Room* _room) {
    _self->vel.x *= 0.6;
    _self->vel.y *= 0.6;

    PlayerSpecData* pspec = (PlayerSpecData*) _self->spec;
    updatePlayerSpec(pspec, _self);

    if (buttonPressed(_BUTTON_RIGHT_)) {
        _self->vel.x += 0.5;
        _self->facing = RIGHT;
        spriteSetOffset(_self->sprite, 16);
        spriteSetHorizontalFlip(_self->sprite, 0);
    }

    if (buttonPressed(_BUTTON_LEFT_)) {
        _self->vel.x -= 0.5;

        _self->facing = LEFT;
        spriteSetOffset(_self->sprite, 16);
        spriteSetHorizontalFlip(_self->sprite, 1);
    }

    if (buttonPressed(_BUTTON_DOWN_)) {
        _self->vel.y += 0.5;

        _self->facing = DOWN;
        spriteSetOffset(_self->sprite, 8);
    }

    if (buttonPressed(_BUTTON_UP_)) {
        _self->vel.y -= 0.5;

        _self->facing = UP;
        spriteSetOffset(_self->sprite, 0);
    }
    
    if (buttonPressed(_BUTTON_A_)) {
        if (_self->attack_cooldown == 0) {
            playerAttack(_self, _room);
            _self->attack_cooldown = 10;
        }
    }

    CollisionType xCol = worldCollision(_world, newIVec2(_self->position.x + _self->vel.x, _self->position.y));
    if(xCol == NONE || xCol == OPENED_DOOR) {
        _self->position.x += _self->vel.x;
    }

    CollisionType yCol = worldCollision(_world, newIVec2(_self->position.x, _self->position.y + _self->vel.y));
    if(yCol == NONE || yCol == OPENED_DOOR) {
        _self->position.y += _self->vel.y;
    }

    if(xCol == OPENED_DOOR || yCol == OPENED_DOOR) {
        (*pspec->next_sprite_index) = 10;

        if(_self->position.y < 70) {
            _self->position = newFVec2(_SCREEN_WIDTH_ / 2 - 8, 128);
            nextRoom(_world, pspec->sprites, pspec->next_sprite_index);
        } else {
            _self->position = newFVec2(_SCREEN_WIDTH_ / 2 - 8, 18);
            backRoom(_world, pspec->sprites, pspec->next_sprite_index);
        }

        _self->health =  
            _self->base_stats.stamina + 
            pspec->armor_slot.base_stats.stamina + 
            pspec->hand_slot.base_stats.stamina;
    }
}
