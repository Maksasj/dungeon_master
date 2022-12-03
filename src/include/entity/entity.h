#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "statblock.h"

#include "../rotation.h"
#include "../sprite.h"
#include "../types.h"

//TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities

typedef struct Entity {
    Sprite* sprite;
    SpriteSize sprite_size_in_pixels;

    fvec2 position;
    fvec2 vel;

    //TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities
    Statblock base_stats;
    
    i32 health;
    i32 mana;

    Facing facing;
    
    u32 sprite_offset;
    i32 attack_cooldown;

    void* spec;

    //void (*update_callback)(Entity* _self, World* _world, Room* _room);
    void (*update_callback)(void*, void*, void*);
    
    //i32 (*attack_callback)();
    i32 (*attack_callback)();

    //void (*cooldown_callback)(Entity* _self)
    void (*cooldown_callback)(void*);

    //void (*die_callback)(Entity* _self);
    void (*die_callback)(void*);

    //void (*spawn_callback)(Entity* _self, Room* _room);
    void (*spawn_callback)(void*, void*);

    //i32 (*on_collision_enter)(Entity* _self, Entity* target);
    i32 (*on_collision_enter)(void*, void*);
} Entity;

Entity entityInit(fvec2 _position, Statblock _stat, u32 _sprite_offset);

void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index);

void entityUnloadSprite(Entity *_entity);

void entityUpdate(Entity* _entity);

void entityAttack(Entity* _entity, Entity* _target);

void entityTakeDamage(Entity* _entity, i32 _damage);

i32 checkCollision(Entity* _first_entity, Entity* _second_entity);

void killEntity(Entity* _entity);

//Pseudo monad lol
Entity addUpdate_CallBack(void (*update_callback)(void*, void*, void*), Entity _entity);
Entity addAttack_CallBack(void (*attack_callback)(void*, void*), Entity _entity);
Entity addTakeDamage_CallBack(void (*takeDamage_callback)(void*, i32), Entity _entity);
Entity addDie_CallBack(void (*die_callback)(void*), Entity _entity);
Entity addSpawn_CallBack(void (*spawn_callback)(void*, void*), Entity _entity);
Entity addOnCollisionEnter_CallBack(i32 (*on_collision_enter)(void*, void*), Entity _entity);

#endif
