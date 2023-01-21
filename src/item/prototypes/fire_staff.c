#include "../../../include/item/prototypes/fire_staff.h"

void fireStaffUseCallback(Entity* _use_target, Room* _active_room) {
    if (_active_room->current_projectile_count + 4 >= _MAX_PROJECTILE_PER_ROOM_) return;
    
    PlayerSpecData* pspec = (PlayerSpecData*) _use_target->spec;
    
    Projectile projectile = (Projectile) {
        .position = newIVec2(_use_target->position.x, _use_target->position.y),

        .layer = PLAYER,

        .facing = UP,
        .update_callback = &projectileUpdate,
        .die_callback = &destroyProjectile,
        .calculate_damage_callback = _use_target->calculate_damage_callback
    };

    entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);
    rotateProjectile(&projectile, 568, 712);
    
    tryPushProjectileToRoom(_active_room, projectile);
}
