#include "include/entity/entity.h"

Entity entityInit(fvec2 _position, u32 _health) {
    Entity _entity;
    _entity.position = _position;
    _entity.vel = newFVec2(0, 0);

    _entity.base_stats = stats(1, 1, 1, 1, 1);
    
    _entity.attack_cooldown = 0;

    _entity.health = _health;
    _entity.mana = 0;
    return _entity;
}

void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index) {
    _entity->sprite = spriteInit(_sprites, _next_sprite_index, _entity->position.x, _entity->position.y, SIZE_16_16, 0, 0, 0, 1);
    _entity->sprite_size_in_pixels = SIZE_16_16;
}

void entityUnloadSprite(Entity *_entity) {
    spritePosition(_entity->sprite, -64, -64);
    _entity->sprite = NULL;
}

void entityUpdate(Entity* _entity) {
    spritePosition(_entity->sprite, (i32) _entity->position.x, (i32)_entity->position.y);
}

void entityAttack(Entity* _entity, Entity* _target) {
    i32 calculated_damage = (*_entity->attack_callback)();

    entityTakeDamage(_target, calculated_damage);

    (*_entity->cooldown_callback)(_entity);
}

void entityTakeDamage(Entity* _entity, i32 _damage) {
    _entity->health -= _damage;

    if (_entity->health <= 0) {
        killEntity(_entity);
    }
}

i32 checkCollision(Entity* _first_entity, Entity* _second_entity) {
    ivec2 first_entity_sprite_size_in_pixels = getSpriteWidthAndLength(_first_entity->sprite_size_in_pixels);
    ivec2 second_entity_sprite_size_in_pixels = getSpriteWidthAndLength(_second_entity->sprite_size_in_pixels);

    if (_first_entity->position.x < _second_entity->position.x + second_entity_sprite_size_in_pixels.x &&
        _first_entity->position.x + first_entity_sprite_size_in_pixels.x > _second_entity->position.x &&
        _first_entity->position.y < _second_entity->position.y + second_entity_sprite_size_in_pixels.y &&
        _first_entity->position.y + first_entity_sprite_size_in_pixels.y > _second_entity->position.y) {
            return 1;
        }
    
    return 0;
}

void killEntity(Entity* _entity) {
    (*_entity->die_callback)(_entity);
    entityUnloadSprite(_entity);
}
