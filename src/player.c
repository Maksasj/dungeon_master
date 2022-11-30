#include "include/player.h"

void initPlayerSpec(Sprite _sprites[], i32* _next_sprite_index, Entity* _entity, PlayerSpecData* pspec) {
    pspec->armor = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
    pspec->weapon = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);

    spriteSetOffset(pspec->armor, 32);
    spriteSetOffset(pspec->weapon, 32);
}

void updatePlayerSpec(PlayerSpecData* pspec, Entity *_entity) {
    spritePosition(pspec->armor, (i32) _entity->position.x, (i32)_entity->position.y);
    spritePosition(pspec->weapon, (i32) _entity->position.x, (i32)_entity->position.y);
}
