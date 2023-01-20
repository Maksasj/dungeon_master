#include "../../../include/item/prototypes/fire_staff.h"

void fireStaffUseCallback(Entity* _use_target, Room* _active_room) {
    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_) return;

    PlayerSpecData* pspec = (PlayerSpecData*) _use_target->spec;
    
    {
        Entity projectile = entityReload((Entity){
            .position = (ivec2){ .x = _use_target->position.x, .y = _use_target->position.y },

            .layer = PLAYER,
            .update_callback = &projectileUpdate,
            .die_callback = &destroyProjectile,
            .facing = UP,
            .calculate_damage_callback = _use_target->calculate_damage_callback
        });

        entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);

        rotateProjectile(&projectile, UP, 568, 712);

        tryPushProjectileToRoom(_active_room, projectile);
    }

    {
        Entity projectile = entityReload((Entity){
            .position = (ivec2){ .x = _use_target->position.x, .y = _use_target->position.y },

            .layer = PLAYER,
            .update_callback = &projectileUpdate,
            .die_callback = &destroyProjectile,
            .facing = RIGHT,
            .calculate_damage_callback = _use_target->calculate_damage_callback
        });

        entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);

        rotateProjectile(&projectile, RIGHT, 568, 712);

        tryPushProjectileToRoom(_active_room, projectile);
    }

    {
        Entity projectile = entityReload((Entity){
            .position = (ivec2){ .x = _use_target->position.x, .y = _use_target->position.y },

            .layer = PLAYER,
            .update_callback = &projectileUpdate,
            .die_callback = &destroyProjectile,
            .facing = DOWN,
            .calculate_damage_callback = _use_target->calculate_damage_callback
        });

        entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);

        rotateProjectile(&projectile, DOWN, 568, 712);

        tryPushProjectileToRoom(_active_room, projectile);
    }

    {
        Entity projectile = entityReload((Entity){
            .position = (ivec2){ .x = _use_target->position.x, .y = _use_target->position.y },

            .layer = PLAYER,
            .update_callback = &projectileUpdate,
            .die_callback = &destroyProjectile,
            .facing = LEFT,
            .calculate_damage_callback = _use_target->calculate_damage_callback
        });

        entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);

        rotateProjectile(&projectile, LEFT, 568, 712);

        tryPushProjectileToRoom(_active_room, projectile);
    }
}
