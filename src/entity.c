#include "include/entity/entity.h"

void entityInit(Sprite _sprites[], i32 *_next_sprite_index, Entity *_entity) {
    _entity->position.x = _SCREEN_WIDTH_ / 2 - 8;
    _entity->position.y = _SCREEN_HEIGHT_ / 2 - 8;

    _entity->vel = newFVec2(0, 0);

    _entity->sprite = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
}

void entityUpdate(Entity *_entity) {
    spritePosition(_entity->sprite, (i32) _entity->position.x, (i32)_entity->position.y);
}
