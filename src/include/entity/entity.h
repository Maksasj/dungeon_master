#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "sprite.h"
#include "types.h"

typedef struct Entity {
    Sprite *sprite;

    //TODO: add statblock

    i32 health;
    i32 mana;
} Entity;

void update(void (*ptr)());
void attack(void (*ptr)());
void takeDamage(void (*ptr)());
void die(void (*ptr)());
void spawn(void (*ptr)());

#endif
