#include "../include/entity/statblock.h"

Statblock stats(stattype _stamina, stattype _agility, stattype _intellect, stattype _strength, stattype _armor) {
    return (Statblock){_stamina, _agility, _intellect, _strength, _armor};
}

Statblock sumStatblock(Statblock _a, Statblock _b) {
    return (Statblock){ _a.stamina + _b.stamina, _a.agility + _b.agility, _a.intellect + _b.intellect, _a.strength + _b.strength, _a.armor + _b.armor };
}
