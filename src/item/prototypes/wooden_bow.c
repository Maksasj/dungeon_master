#include "../../../include/item/prototypes/wooden_bow.h"

void woodenBowUseCallback(Entity* _use_target, Room* _active_room) {
    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_) return;

    PlayerSpecData* pspec = (PlayerSpecData*) _use_target->spec;
   
    Projectile projectile = (Projectile) {
        .position.x =  _use_target->position.x,
        .position.y =  _use_target->position.y,

        .vel.x = 0,
        .vel.y = 0,

        .layer = PLAYER,

        .facing = _use_target->facing,
        .update_callback = &projectileUpdate,
        .die_callback = &destroyProjectile,
        .calculate_damage_callback = _use_target->calculate_damage_callback
    };

    entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);

    rotateProjectile(&projectile, _use_target->facing, 576, 720);

    tryPushProjectileToRoom(_active_room, projectile);
}
