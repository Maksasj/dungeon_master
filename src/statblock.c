#include "include/entity/statblock.h"

Statblock stats(stattype stamina, stattype agility, stattype intellect, stattype strength, stattype armor) {
    return (Statblock){stamina, agility, intellect, strength, armor};
}

Statblock sumStatblock(Statblock a, Statblock b) {
    return (Statblock){ a.stamina + b.stamina, a.agility + b.agility, a.intellect + b.intellect, a.strength + b.strength, a.armor + b.armor };
}
