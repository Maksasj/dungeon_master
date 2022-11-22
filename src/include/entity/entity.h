#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "statblock.h"

#include "../sprite.h"
#include "../types.h"

//TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities

typedef struct Entity {
    Sprite *sprite;

    //TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities
    Statblock base_stats;
    
    i32 health;
    i32 mana;

    fvec2 position;
    fvec2 vel;

    void (*update_callback)();
    void (*attack_callback)();
    void (*takeDamage_callback)();
    void (*die_callback)();
    void (*spawn_callback)();
} Entity;

Entity entityInit(fvec2 _position);

void entityInitSprite(Entity *_entity, Sprite _sprites[], i32 *_next_sprite_index);

void entityUpdate(Entity *_entity);

#endif
