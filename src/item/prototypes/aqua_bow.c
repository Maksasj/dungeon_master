#include "../../../include/item/prototypes/aqua_bow.h"

void aquaBowUseCallback(Entity* _use_target, Room* _active_room) {
    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_) return;

    PlayerSpecData* pspec = (PlayerSpecData*) _use_target->spec;
   
    //Entity projectile = entityReload((Entity){
    //    .position = (ivec2){ .x = _use_target->position.x, .y = _use_target->position.y },
//
    //    .layer = PLAYER,
    //    .update_callback = &projectileUpdate,
    //    .die_callback = &destroyProjectile,
    //    .facing = _use_target->facing,
    //    .calculate_damage_callback = _use_target->calculate_damage_callback
    //});

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

    rotateProjectile(&projectile, _use_target->facing, 592, 736);

    tryPushProjectileToRoom(_active_room, projectile);
}
