/**
 * entity
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * allows to create characters
*/

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "statblock.h"
#include "layer_mask.h"

#include "rotation.h"
#include "../sprite.h"
#include "../utils/types.h"
#include "../utils/random.h"

#define _DEFAULT_INVULNERABILITY_TIME_ 1000;
#define _REPULSIVE_FORCE_ 10;

// Entity structure for storing the required information
typedef struct Entity {
    // Textures
    Sprite* sprite;
    // Texture size
    SpriteSize sprite_size_in_pixels;

    // Vector2 position
    ivec2 position;
    // Vector2 velocity
    ivec2 vel;

    // Stats
    Statblock base_stats;
    // Layer
    LayerMask layer;
    
    // health
    i32 health;
    // mana
    i32 mana;

    i32 invulnerable;
    i32 invulnerability_time;

    // facing (UP, RIGHT, LEFT, DOWN)
    Facing facing;
    
    // offset
    u32 sprite_offset;

    // cooldowns
    i32 attack_cooldown;
    i32 max_attack_cooldown;

    // player_detection
    i32 saw_the_target;

    // specs
    void* spec;

    //void (*update_callback)(Entity* _self, World* _world, Room* _room);
    void (*update_callback)(void*, void*, void*);
    
    //void (*attack_callback)(Entity* _self, Room* _room);
    void (*attack_callback)(void*, void*);

    //i32 (*calculate_damage_callback)(Entity* _self);
    i32 (*calculate_damage_callback)(void*);

    //void (*die_callback)(Entity* _self);
    void (*die_callback)(void*);

    //void (*spawn_callback)(Entity* _self, Room* _room);
    void (*spawn_callback)(void*, void*);

    //i32 (*on_collision_enter)(Entity* _self, Entity* target);
    i32 (*on_collision_enter)(void*, void*);

    //i32 (*dodge_callback)(Entity* _self)
    i32 (*dodge_callback)(void*);
} Entity;

/**
 * Initialize entity
 * 
 * @param _position         coordinates
 * @param _stat             stats
 * @param _layer            layer
 * @param _sprite_offset    sprite offset
 * 
 * @return entity object
*/
Entity entityInit(ivec2 _position, Statblock _stat, LayerMask _layer, u32 _sprite_offset);

/**
 * Reload entity
 * 
 * @param _self         entity
 * 
 * @return reloaded entity object
*/
Entity entityReload(Entity _self);

/**
 * Initialize entity sprite
 * 
 * @param _entity               entity
 * @param _sprites              textures
 * @param _next_sprite_index    next sprite index
*/
void entityInitSprite(Entity* _entity, Sprite _sprites[], i32* _next_sprite_index);

/**
 * Unloads sprite from game
 * 
 * @param _entity               existing entity
*/
void entityUnloadSprite(Entity *_entity);

/**
 * Updates entity in worldUpdate
 * 
 * @param _entity         existing entity
*/
void entitySpriteUpdate(Entity* _entity);

/**
 * Handles attack
 * 
 * @param _entity         existing entity (source)
 * @param _target         existing target entity (destination)
*/
void entityAttack(Entity* _entity, Entity* _target);

/**
 * Taking damage
 * 
 * @param _entity         existing entity
 * @param _damage         amount of damage
*/
void entityTakeDamage(Entity* _entity, i32 _damage);

/**
 * Add knockback
 * 
 * @param _entity         existing entity
 * @param _facing         direction
 * @param _power          amount of power
*/
void entityKnockback(Entity* _entity, Facing _facing, i32 _power);

/**
 * Calculates with pseudo-number generator dodge chance
 * 
 * @param _entity      existing entity
 * 
 * @return 0 - receives damage (false), 1 - dodged (true)
*/
i32 tryDodge(Entity* _entity);


/**
 * Checks collision between two entities
 * 
 * @param _first_entity      existing entity
 * @param _second_entity      existing entity
 * 
 * @return 0 - false, 1 - true
*/
i32 checkCollision(Entity* _first_entity, Entity* _second_entity);

/**
 * Kills entity
 * 
 * @param _entity      existing entity
*/
void killEntity(Entity* _entity);

/**
 * Makes entity invulnerable for certain time
 * 
 * @param _entity      existing entity
*/
void makeInvulnerable(Entity* _entity);

#endif
