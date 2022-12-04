#ifndef _STATBLOCK_H_
#define _STATBLOCK_H_

#include "../sprite.h"
#include "../types.h"

typedef i32 stattype;

#define _DEFAULT_ATTACK_COOLDOWN_ 70

#define _MANA_MODIFIER_FROM_INTELLECT_ 10
#define _ATTACK_COOLDOWN_MODIFIER_FROM_AGILITY_ 10
#define _DODGE_CHANCE_FROM_AGILITY_ 10

typedef struct Statblock {
    stattype stamina;
    stattype agility;
    stattype intellect;
    stattype strength;
    stattype armor;
} Statblock;

//TODO create function to calc max hp and max mana, cause as i assume similar function will be used for all entities

Statblock stats(stattype _stamina, stattype _agility, stattype _intellect, stattype _strength, stattype _armor);

Statblock sumStatblock(Statblock _a, Statblock _b);

#endif
