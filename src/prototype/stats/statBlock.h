#ifndef STATBLOCK_H
#define STATBLOCK_H

#include "statType.h"

typedef struct statBlock {
    stattype health;
    stattype defence;

    stattype strength;
    stattype agility;

    stattype stamina;
    stattype intelect;
};

statBlock statBlockSum(statBlock a, statBlock b) {
    statBlock statblock;

    statblock.health = a.health + b.health;
    statblock.defence = a.defence + b.defence;

    statblock.strength = a.strength + b.strength;
    statblock.agility = a.agility + b.agility;

    statblock.stamina = a.stamina + b.stamina;
    statblock.intelect = a.intelect + b.intelect;

    return statblock;
}

statBlock statBlockMinus(statBlock a, statBlock b) {
    statBlock statblock;

    statblock.health = a.health - b.health;
    statblock.defence = a.defence - b.defence;

    statblock.strength = a.strength - b.strength;
    statblock.agility = a.agility - b.agility;

    statblock.stamina = a.stamina - b.stamina;
    statblock.intelect = a.intelect - b.intelect;

    return statblock;
}

statBlock createStatBlock() {
    statBlock statblock;

    statblock.health = 0;
    statblock.defence = 0;

    statblock.strength = 0;
    statblock.agility = 0;

    statblock.stamina = 0;
    statblock.intelect = 0;

    return statblock;
}

#endif
