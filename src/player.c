#include "include/player.h"

void initPlayerSpec(Sprite _sprites[], i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec) {
    _pspec->armor = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
    _pspec->weapon = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);

    spriteSetOffset(_pspec->armor, 144);
    spriteSetOffset(_pspec->weapon, 200);
}

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity) {
    spritePosition(_pspec->armor, (i32) _entity->position.x, (i32)_entity->position.y);
    spritePosition(_pspec->weapon, (i32) _entity->position.x, (i32)_entity->position.y);
}
