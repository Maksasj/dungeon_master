#include "../../../include/entity/prototypes/archer.h"

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

    /*
    592 - cobalt arrow horizontal | 736 - cobalt arrow vertical
    584 - golden arrow horizontal | 728 - golden arrow vertical
    576 - iron arrow   horizontal | 720 - iron arrow   vertical

    568 - fireball horizontal     | 712 - fireball vertical
    560 - iceball  horizontal     | 704 - iceball  vertical
    552 - gemball  horizontal     | 696 - gemball  vertical
    */

    /*
    480 - wooden bow
    504 - golden bow
    528 - aqua bow
    */

    i32 sprite_offset_horizontal = 576;
    i32 sprite_offset_vertical = 720;

    switch (pspec->hand_slot.sprite_offset) {
        case 480: {
            sprite_offset_horizontal = 576;
            sprite_offset_vertical = 720;
            break;
        }
        case 504: {
            sprite_offset_horizontal = 584;
            sprite_offset_vertical = 728;
            break;
        }
        case 528: {
            sprite_offset_horizontal = 592;
            sprite_offset_vertical = 736;
            break;
        }
    }

    switch (_archer->facing) {
        case UP:
            spriteSetOffset(projectile.sprite, sprite_offset_vertical);
            spriteSetVerticalFlip(projectile.sprite, 1);
            break;
        case RIGHT: 
            spriteSetOffset(projectile.sprite, sprite_offset_horizontal);
            spriteSetHorizontalFlip(projectile.sprite, 0);
            break;
        case DOWN:
            spriteSetOffset(projectile.sprite, sprite_offset_vertical);
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
