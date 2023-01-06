#ifndef _ENTITY_H_
#define _ENTITY_H_

#define HEALTH_CAP 6

#define VELOCITY_CONSTANT 4
#define VELOCITY_SLOWDOWN_CONSTANT 1

#define POSITION_FIXED_SCALAR 5

#include "statblock.h"

#include "rotation.h"
#include "../sprite.h"
#include "../utils/types.h"
#include "../utils/random.h"

typedef struct Entity {
    Sprite* sprite;
    SpriteSize sprite_size_in_pixels;

    ivec2 position;
    ivec2 vel;

    //TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities
    Statblock base_stats;
    
    i32 health;
    i32 mana;

    Facing facing;
    
    u32 sprite_offset;
    i32 attack_cooldown;
    i32 max_attack_cooldown;

    i32 saw_the_target;

    void* spec;

    //void (*update_callback)(Entity* _self, World* _world, Room* _room);
    void (*update_callback)(void*, void*, void*);
    
    //i32 (*attack_callback)(Entity* _self);
    i32 (*attack_callback)(void*);

    //void (*die_callback)(Entity* _self);
    void (*die_callback)(void*);

    //void (*spawn_callback)(Entity* _self, Room* _room);
    void (*spawn_callback)(void*, void*);

    //i32 (*on_collision_enter)(Entity* _self, Entity* target);
    i32 (*on_collision_enter)(void*, void*);

    //i32 (*dodge_callback)(Entity* _self)
    i32 (*dodge_callback)(void*);
} Entity;

Entity entityInit(ivec2 _position, Statblock _stat, u32 _sprite_offset);

Entity entityReload(Entity _self);

void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index);

void entityUnloadSprite(Entity *_entity);

void entityUpdate(Entity* _entity);

void entityAttack(Entity* _entity, Entity* _target);

void entityTakeDamage(Entity* _entity, i32 _damage);

void entityKnockback(Entity* _entity, Facing _facing, i32 _power);

i32 tryDodge(Entity* _entity);

i32 checkCollision(Entity* _first_entity, Entity* _second_entity);

void killEntity(Entity* _entity);

#endif
