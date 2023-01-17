#include "../../include/entity/statblock.h"

Statblock statsInit(stattype _stamina, stattype _agility, stattype _intellect, stattype _strength, stattype _armor) {
    return (Statblock){_stamina, _agility, _intellect, _strength, _armor};
}
