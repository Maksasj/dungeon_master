#include "include/player.h"

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec) {
    _pspec->armor = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
    _pspec->weapon = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);

    _pspec->sprites = _sprites;
    _pspec->next_sprite_index = _next_sprite_index;

    spriteSetOffset(_pspec->armor, 144);
    spriteSetOffset(_pspec->weapon, 200);
}

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index) {
    _playerUI->health[0] = spriteInit(_sprites, _next_sprite_index, 4, 3, SIZE_16_16, 0, 0, 0, 0);
    _playerUI->health[1] = spriteInit(_sprites, _next_sprite_index, 20, 3, SIZE_16_16, 0, 0, 0, 0);
    _playerUI->health[2] = spriteInit(_sprites, _next_sprite_index, 36, 3, SIZE_16_16, 0, 0, 0, 0);
    spriteSetOffset(_playerUI->health[0], 280);
    spriteSetOffset(_playerUI->health[1], 280);
    spriteSetOffset(_playerUI->health[2], 280);

    _playerUI->manaBar = spriteInit(_sprites, _next_sprite_index, 4, 20, SIZE_32_16, 0, 0, 0, 0);
    spriteSetOffset(_playerUI->manaBar, 288);
}

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity) {
    spritePosition(_pspec->armor, (i32) _entity->position.x, (i32)_entity->position.y);
    spritePosition(_pspec->weapon, (i32) _entity->position.x, (i32)_entity->position.y);
}


void playerAttack(Entity* _player, Room* _active_room) {
    i32 i;

    for(i = 0; i < _active_room->current_entity_count; ++i) {
        Entity *entity = &_active_room->entity_pool[i];

        if ((*entity->on_collision_enter)(entity, _player)) {
            entityAttack(_player, entity);
        }
    }
}

i32 playerCalculateDamage() {
    //TODO: calculate damage
    return 1;
}

void playerSetAttackCooldown(Entity* _self) {
    //TODO: calculate cooldown
    _self->attack_cooldown = 1;
}

void killPlayer(Entity* _self) {
    //TODO: restart the game
    return;
}

void player_update(Entity* _self, World* _world, Room* _room) {
    _self->vel.x *= 0.6;
    _self->vel.y *= 0.6;

    PlayerSpecData* pspec = (PlayerSpecData*) _self->spec;

    if (buttonPressed(_BUTTON_RIGHT_)) {
        _self->vel.x += 0.5;

        spriteSetOffset(_self->sprite, 16);
        spriteSetHorizontalFlip(_self->sprite, 0);

        //notePlay(NOTE_BES, octave + 1);
    }

    if (buttonPressed(_BUTTON_LEFT_)) {
        _self->vel.x -= 0.5;

        spriteSetOffset(_self->sprite, 16);
        spriteSetHorizontalFlip(_self->sprite, 1);

        //notePlay(NOTE_B, octave);
    }

    if (buttonPressed(_BUTTON_DOWN_)) {
        _self->vel.y += 0.5;
        spriteSetOffset(_self->sprite, 8);

        //notePlay(NOTE_F, octave);
    }

    if (buttonPressed(_BUTTON_UP_)) {
        _self->vel.y -= 0.5;
        spriteSetOffset(_self->sprite, 0);

        //notePlay(NOTE_A, octave);
    }
    
    if (buttonPressed(_BUTTON_A_)) {
        if (_self->attack_cooldown == 0) {
            playerAttack(_self, _room);
            (*_self->cooldown_callback)(_self);
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
