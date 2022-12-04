#include "include/entity/entity.h"

Entity entityInit(fvec2 _position, Statblock _stat, u32 _sprite_offset) {
    Entity _entity;
    _entity.position = _position;
    _entity.vel = newFVec2(0, 0);

    _entity.base_stats = _stat;

    _entity.sprite_offset = _sprite_offset;

    _entity.health = _stat.stamina;
    _entity.mana = _stat.intellect * _MANA_MODIFIER_FROM_INTELLECT_;
    _entity.attack_cooldown = 0;
    _entity.max_attack_cooldown = _DEFAULT_ATTACK_COOLDOWN_ - _ATTACK_COOLDOWN_MODIFIER_FROM_AGILITY_ * _stat.agility;

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
    i32 calculated_damage = (*_entity->attack_callback)(_entity);
    entityTakeDamage(_target, calculated_damage);
}

void entityTakeDamage(Entity* _entity, i32 _damage) {
    _damage -= _entity->base_stats.armor;

    if (_damage < 0) {
        _damage = 0;
    }

    _entity->health -= _damage;

    if (_entity->health <= 0) {
        killEntity(_entity);
    }
}

void entityKnockback(Entity* _entity, Facing _facing, float _power) {
    switch (_facing)
    {
        case UP:
            _entity->vel.y -= _power;
            break;
        case RIGHT:
            _entity->vel.x += _power;
            break;
        case DOWN:
            _entity->vel.y += _power;
            break;
        case LEFT:
            _entity->vel.x -= _power;
            break;
        default:
            break;
    }
}

i32 checkCollision(Entity* _first_entity, Entity* _second_entity) {
    //ivec2 first_entity_sprite_size_in_pixels = getSpriteWidthAndLength(_first_entity->sprite_size_in_pixels);
    //ivec2 second_entity_sprite_size_in_pixels = getSpriteWidthAndLength(_second_entity->sprite_size_in_pixels);

    ivec2 first_entity_sprite_size_in_pixels = newIVec2(16, 16);
    ivec2 second_entity_sprite_size_in_pixels = newIVec2(16, 16);

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

//Pseudo monad lol
Entity addUpdate_CallBack(void (*update_callback)(void*, void*, void*), Entity _entity) {
    _entity.update_callback = update_callback;
    return _entity;
}

Entity addAttack_CallBack(i32 (*attack_callback)(void*), Entity _entity) {
    _entity.attack_callback = attack_callback;
    return _entity;
}

Entity addDie_CallBack(void (*die_callback)(void*), Entity _entity) {
    _entity.die_callback = die_callback;
    return _entity;
}

Entity addSpawn_CallBack(void (*spawn_callback)(void*, void*), Entity _entity) {
    _entity.spawn_callback = spawn_callback;
    return _entity;
}

Entity addOnCollisionEnter_CallBack(i32 (*on_collision_enter)(void*, void*), Entity _entity) {
    _entity.on_collision_enter = on_collision_enter;
    return _entity;
}

Entity addDodgeCallback(i32 (*dodge_callback)(void*), Entity _entity) {
    _entity.dodge_callback = dodge_callback;
    return _entity;
}
