#include "../../include/entity/wizard.h"

void wizardAttack(Entity* _wizard, Room* _active_room) {
    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_) {
        return;
    }

    PlayerSpecData* pspec = (PlayerSpecData*)_wizard->spec;

    Entity projectile = projectileInit(_wizard->position, PLAYER, 0);
    projectile.update_callback = &projectileUpdate;
    projectile.die_callback = &destroyProjectile;
    projectile.calculate_damage_callback = &wizardCalculateDamage;

    entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);
    projectile.facing = _wizard->facing;

    tryPushProjectileToRoom(_active_room, projectile);
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
