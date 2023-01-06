#include "../../include/entity/entity.h"
#include "../../include/world/world.h"

Entity entityReload(Entity _self) {
    _self.vel = newIVec2(0, 0);
    _self.saw_the_target = 0;
    _self.health = _self.base_stats.stamina;

    _self.mana = _self.base_stats.intellect * _MANA_MODIFIER_FROM_INTELLECT_;
    _self.attack_cooldown = 0;
    _self.max_attack_cooldown = _DEFAULT_ATTACK_COOLDOWN_ - _ATTACK_COOLDOWN_MODIFIER_FROM_AGILITY_ * _self.base_stats.agility;
    return _self;
}

Entity entityInit(ivec2 _position, Statblock _stat, LayerMask _layer, u32 _sprite_offset) {
    Entity _entity;
    
    _entity.position.x = _position.x << POSITION_FIXED_SCALAR;
    _entity.position.y = _position.y << POSITION_FIXED_SCALAR;

    _entity.vel = newIVec2(0, 0);

    _entity.saw_the_target = 0;

    _entity.base_stats = _stat;
    _entity.layer = _layer;

    _entity.sprite_offset = _sprite_offset;

    _entity.health = _stat.stamina;
    _entity.mana = _stat.intellect * _MANA_MODIFIER_FROM_INTELLECT_;
    _entity.attack_cooldown = 0;
    _entity.max_attack_cooldown = _DEFAULT_ATTACK_COOLDOWN_ - _ATTACK_COOLDOWN_MODIFIER_FROM_AGILITY_ * _stat.agility;

    return _entity;
}

void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index) {
    _entity->sprite = spriteInit(
        _sprites, 
        _next_sprite_index, 
        _entity->position.x >> POSITION_FIXED_SCALAR, 
        _entity->position.y >> POSITION_FIXED_SCALAR, 
        SIZE_16_16, 
        0, 0, 0, 3);
    
    _entity->sprite_size_in_pixels = SIZE_16_16;
}

void entityUnloadSprite(Entity *_entity) {
    spritePosition(_entity->sprite, -64, -64);
    _entity->sprite = NULL;
}

void entityUpdate(Entity* _entity) {
    spritePosition(_entity->sprite, (i32) _entity->position.x >> POSITION_FIXED_SCALAR, (i32)_entity->position.y >> POSITION_FIXED_SCALAR);
}

void entityAttack(Entity* _entity, Entity* _target) {
    i32 calculated_damage = (*_entity->calculate_damage_callback)(_entity);
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

void entityKnockback(Entity* _entity, Facing _facing, i32 _power) {
    switch (_facing)
    {
        case UP: {
            _entity->vel.y -= _power;
            break;
        }
        case RIGHT: {
            _entity->vel.x += _power;
            break;
        }
        case DOWN: {
            _entity->vel.y += _power;
            break;
        }
        case LEFT: {
            _entity->vel.x -= _power;
            break;
        }
        default:
            break;
    }
}

i32 checkCollision(Entity* _first_entity, Entity* _second_entity) {
    ivec2 first_entity_sprite_size_in_pixels = newIVec2(16, 16);
    ivec2 second_entity_sprite_size_in_pixels = newIVec2(16, 16);

    ivec2 first_entity_fixed_position = newIVec2(_first_entity->position.x >> POSITION_FIXED_SCALAR, _first_entity->position.y >> POSITION_FIXED_SCALAR);
    ivec2 second_entity_fixed_position = newIVec2(_second_entity->position.x >> POSITION_FIXED_SCALAR, _second_entity->position.y >> POSITION_FIXED_SCALAR);

    if (first_entity_fixed_position.x < second_entity_fixed_position.x + second_entity_sprite_size_in_pixels.x &&
        first_entity_fixed_position.x + first_entity_sprite_size_in_pixels.x > second_entity_fixed_position.x &&
        first_entity_fixed_position.y < second_entity_fixed_position.y + second_entity_sprite_size_in_pixels.y &&
        first_entity_fixed_position.y + first_entity_sprite_size_in_pixels.y > second_entity_fixed_position.y) {
            return 1;
    }
    
    return 0;
}

void killEntity(Entity* _entity) {
    (*_entity->die_callback)(_entity);
    entityUnloadSprite(_entity);
    _entity->saw_the_target = 0;
}
