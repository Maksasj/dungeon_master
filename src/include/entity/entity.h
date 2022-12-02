#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "statblock.h"

#include "../sprite.h"
#include "../types.h"
#include "../logger.h"

//TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities

typedef struct Entity {
    Sprite* sprite;
    SpriteSize sprite_size_in_pixels;

    //TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities
    Statblock base_stats;
    
    i32 health;
    i32 mana;

    i32 attack_cooldown;

    fvec2 position;
    fvec2 vel;

    void* spec;

    //void (*update_callback)(Entity* _self, World* _world, Room* _room);
    void (*update_callback)(void*, void*, void*);
    
    //i32 (*attack_callback)();
    i32 (*attack_callback)();

    //void (*takeDamage_callback)(Entity* _self, i32 _damage);
    void (*takeDamage_callback)(void*, i32);

    //void (*die_callback)(Entity* _self);
    void (*die_callback)(void*);

    //void (*spawn_callback)(Entity* _self, Room* _room);
    void (*spawn_callback)(void*, void*);

    //i32 (*on_collision_enter)(Entity* _self, Entity* target);
    i32 (*on_collision_enter)(void*, void*);
} Entity;

Entity entityInit(fvec2 _position, u32 _health);

void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index);

void entityUnloadSprite(Entity *_entity);

void entityUpdate(Entity* _entity);

void entityAttack(Entity* _entity, Entity* _target);

void entityTakeDamage(Entity* _entity, i32 _damage);

i32 checkCollision(Entity* _first_entity, Entity* _second_entity);

void killEntity(Entity* _entity);

#endif
