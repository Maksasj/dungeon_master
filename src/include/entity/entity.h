#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../sprite.h"
#include "../types.h"

typedef struct Entity {
    Sprite *sprite;

    //TODO: add statblock

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

void entityInit(Sprite _spites[], i32 *_next_sprite_index, Entity *_entity);

void entityUpdate(Entity *_entity);

#endif
