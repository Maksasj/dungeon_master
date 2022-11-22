#include "include/entity/entity.h"

Entity entityInit(fvec2 _position) {
    Entity _entity;
    _entity.position = _position;
    _entity.vel = newFVec2(0, 0);

    _entity.base_stats = stats(1, 1, 1, 1, 1);

    _entity.health = 0;
    _entity.mana = 0;
    return _entity;
}

void entityInitSprite(Entity *_entity, Sprite _sprites[], i32 *_next_sprite_index) {
    _entity->sprite = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
}

void entityUpdate(Entity *_entity) {
    spritePosition(_entity->sprite, (i32) _entity->position.x, (i32)_entity->position.y);
}
