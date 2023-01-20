#include "../../../include/entity/prototypes/wizard.h"

void wizardAttack(Entity* _wizard, Room* _active_room) {
    if (_active_room->current_projectile_count >= _MAX_PROJECTILE_PER_ROOM_) {
        return;
    }

    PlayerSpecData* pspec = (PlayerSpecData*)_wizard->spec;
   
    Entity projectile = projectileInit(
        (ivec2){.x = _wizard->position.x >> _POSITION_FIXED_SCALAR_, .y = _wizard->position.y >> _POSITION_FIXED_SCALAR_},
         PLAYER, 0); // <- TEXTURE offset
    projectile.update_callback = &projectileUpdate;
    projectile.die_callback = &destroyProjectile;
    projectile.calculate_damage_callback = &wizardCalculateDamage;

    entityInitSprite(&projectile, pspec->sprites, pspec->next_sprite_index);
    projectile.facing = _wizard->facing;

    /*
    592 - cobalt arrow horizontal | 736 - cobalt arrow vetical
    584 - golden arrow horizontal | 728 - golden arrow vetical
    576 - iron arrow   horizontal | 720 - iron arrow   vetical

    568 - fireball horizontal     | 712 - fireball vetical
    560 - iceball  horizontal     | 704 - iceball  vetical
    552 - gemball  horizontal     | 696 - gemball  vetical
    */

    /*
    408 - gem staff
    432 - ice staff
    456 - fire staff
    */

    i32 sprite_offset_horizontal = 552;
    i32 sprite_offset_vetical = 696;

    switch (pspec->hand_slot.sprite_offset) {
        case 408: {
            sprite_offset_horizontal = 552;
            sprite_offset_vetical = 696;
            break;
        }
        case 432: {
            sprite_offset_horizontal = 560;
            sprite_offset_vetical = 704;
            break;
        }
        case 456: {
            sprite_offset_horizontal = 568;
            sprite_offset_vetical = 712;
            break;
        }
    }

    switch (_wizard->facing) {
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
