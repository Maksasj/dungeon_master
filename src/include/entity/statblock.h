#ifndef _STATBLOCK_H_
#define _STATBLOCK_H_

#include "../sprite.h"
#include "../types.h"

typedef i32 stattype;

typedef struct Statblock {
    stattype stamina;
    stattype agility;
    stattype intellect;
    stattype strength;
    stattype armor;
} Statblock;

//TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities

Statblock stats(stattype stamina, stattype agility, stattype intellect, stattype strength, stattype armor);

Statblock sumStatblock(Statblock a, Statblock b);

#endif
