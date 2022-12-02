#include "include/player.h"

void initPlayerSpec(Sprite _sprites[], i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec) {
    _pspec->armor = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
    _pspec->weapon = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);

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

i32 playerCalculateDamage() {
    return 1;
}

void playerSetAttackCooldown(Entity* _self) {
    //TODO: calculate cooldown
    _self->attack_cooldown = 1;
}
