#include "../../include/entity/archer.h"

void archerAttack(Entity* _archer, Room* _active_room) {
    //TODO: projectile spawning
}

i32 archerCalculateDamage(Entity* _archer) {
    PlayerSpecData* pspec = (PlayerSpecData*)_archer->spec;
    Item *hand = &pspec->hand_slot;
    Item *armor = &pspec->armor_slot;

    i32 agility = _archer->base_stats.agility + hand->base_stats.agility + armor->base_stats.agility;

    if (agility < 0) {
        agility = 0;
    }

    return 1 + agility;
}
