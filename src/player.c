#include "include/player.h"
#include "include/logger.h"

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index) {
    _playerUI->health[0] = spriteInit(_sprites, _next_sprite_index, 4, 3, SIZE_16_16, 0, 0, 0, 0);
    _playerUI->health[1] = spriteInit(_sprites, _next_sprite_index, 20, 3, SIZE_16_16, 0, 0, 0, 0);
    _playerUI->health[2] = spriteInit(_sprites, _next_sprite_index, 36, 3, SIZE_16_16, 0, 0, 0, 0);
    spriteSetOffset(_playerUI->health[0], 304);
    spriteSetOffset(_playerUI->health[1], 304);
    spriteSetOffset(_playerUI->health[2], 304);

    _playerUI->manaBar = spriteInit(_sprites, _next_sprite_index, 4, 20, SIZE_32_16, 0, 0, 0, 0);
    spriteSetOffset(_playerUI->manaBar, 312);
}

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec) {
    _pspec->armor = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
    _pspec->weapon = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);

    spritePosition(_pspec->armor, -64, -64);
    spritePosition(_pspec->weapon, -64, -64);

    _pspec->sprites = _sprites;
    _pspec->next_sprite_index = _next_sprite_index;
    
    _pspec->hand_slot.count = 0;
    _pspec->armor_slot.count = 0;

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

    CollisionType xCol = worldCollision(_world, newIVec2(_self->position.x + _self->vel.x, _self->position.y));
    if(xCol == NONE || xCol == OPENED_DOOR)
        _self->position.x += _self->vel.x;

    CollisionType yCol = worldCollision(_world, newIVec2(_self->position.x, _self->position.y + _self->vel.y));
    if(yCol == NONE || yCol == OPENED_DOOR)
        _self->position.y += _self->vel.y;

    if(xCol == OPENED_DOOR || yCol == OPENED_DOOR) {
        (*pspec->next_sprite_index) = 7;

        if(_self->position.y < 70) {
            _self->position = newFVec2(_SCREEN_WIDTH_ / 2 - 8, 128);
            nextRoom(_world, pspec->sprites, pspec->next_sprite_index);
        } else {
            _self->position = newFVec2(_SCREEN_WIDTH_ / 2 - 8, 18);
            backRoom(_world, pspec->sprites, pspec->next_sprite_index);
        }
    }
}
