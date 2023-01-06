#include "../../include/entity/archer.h"

void archerAttack(Entity* _archer, Room* _active_room) {
    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_) {
        return;
    }

    PlayerSpecData* pspec = (PlayerSpecData*)_archer->spec;

    Entity projectile = projectileInit(
        (ivec2){.x = _archer->position.x >> POSITION_FIXED_SCALAR, .y = _archer->position.y >> POSITION_FIXED_SCALAR},
         PLAYER, 0); // <- TEXTURE offset
    projectile.update_callback = &projectileUpdate;
    projectile.die_callback = &destroyProjectile;
    projectile.calculate_damage_callback = &archerCalculateDamage;

    entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);
    projectile.facing = _archer->facing;

    tryPushProjectileToRoom(_active_room, projectile);
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
