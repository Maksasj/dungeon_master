#include "../../include/entity/wizard.h"

void wizardAttack(Entity* _wizard, Room* _active_room) {

}

i32 wizardCalculateDamage(Entity* _wizard) {
    PlayerSpecData* pspec = (PlayerSpecData*)_wizard->spec;
    Item *hand = &pspec->hand_slot;
    Item *armor = &pspec->armor_slot;

    i32 intellect = _wizard->base_stats.intellect + hand->base_stats.intellect + armor->base_stats.intellect;

    if (intellect < 0) {
        intellect = 0;
    }

    return 1 + intellect;
}
