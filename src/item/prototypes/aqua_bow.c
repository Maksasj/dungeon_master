#include "../../../include/item/prototypes/aqua_bow.h"

void aquaBowUseCallback(Entity* _use_target, Room* _active_room) {
    log(LOG_INFO, "Used aqua bow");

    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_)
        return;

    PlayerSpecData* pspec = (PlayerSpecData*) _use_target->spec;
   
    Entity projectile = projectileInit(
        (ivec2){.x = _use_target->position.x >> POSITION_FIXED_SCALAR, .y = _use_target->position.y >> POSITION_FIXED_SCALAR},
         PLAYER, 0); // <- TEXTURE offset
    projectile.update_callback = &projectileUpdate;
    projectile.die_callback = &destroyProjectile;
    projectile.calculate_damage_callback = _use_target->calculate_damage_callback;

    entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);
    projectile.facing = _use_target->facing;

    /*
    592 - cobalt arrow horizontal | 736 - cobalt arrow vetical
    584 - golden arrow horizontal | 728 - golden arrow vetical
    576 - iron arrow   horizontal | 720 - iron arrow   vetical

    568 - fireball horizontal     | 712 - fireball vetical
    560 - iceball  horizontal     | 704 - iceball  vetical
    552 - gemball  horizontal     | 696 - gemball  vetical
    */

    i32 sprite_offset_horizontal = 592;
    i32 sprite_offset_vetical = 736;

    switch (_use_target->facing) {
        case UP:
            spriteSetOffset(projectile.sprite, sprite_offset_vetical);
            spriteSetVerticalFlip(projectile.sprite, 1);
            break;
        case RIGHT: 
            spriteSetOffset(projectile.sprite, sprite_offset_horizontal);
            spriteSetHorizontalFlip(projectile.sprite, 0);
            break;
        case DOWN:
            spriteSetOffset(projectile.sprite, sprite_offset_vetical);
            spriteSetVerticalFlip(projectile.sprite, 0);
            break;
        case LEFT:
            spriteSetOffset(projectile.sprite, sprite_offset_horizontal);
            spriteSetHorizontalFlip(projectile.sprite, 1);
            break;
        default:
            break;
    }

    tryPushProjectileToRoom(_active_room, projectile);
}
