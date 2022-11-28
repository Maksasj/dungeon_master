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

void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index) {
    _entity->sprite = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 0);
}

void entityUnloadSprite(Entity *_entity) {
    spritePosition(_entity->sprite, -64, -64);
    _entity->sprite = NULL;
}

void entityUpdate(Entity* _entity) {
    spritePosition(_entity->sprite, (i32) _entity->position.x, (i32)_entity->position.y);
}

i32 checkCollision(Entity* _first_entity, Entity* _second_entity) {
    ivec2 first_entity_sprite_size = getSpriteWidthAndLength(_first_entity->sprite);
    ivec2 second_entity_sprite_size = getSpriteWidthAndLength(_second_entity->sprite);

    if (_first_entity->position.x < _second_entity->position.x + second_entity_sprite_size.x &&
        _first_entity->position.x + first_entity_sprite_size.x > _second_entity->position.x &&
        _first_entity->position.y < _second_entity->position.y + second_entity_sprite_size.y &&
        _first_entity->position.y + first_entity_sprite_size.y > _second_entity->position.y) {
            return 1;
        }
    
    return 0;
}

void killEntity(Entity* _entity) {
    (*_entity->die_callback)(_entity);
    entityUnloadSprite(_entity);
}
