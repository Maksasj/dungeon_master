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

    /*
    592 - cobalt arrow horizontal | 736 - cobalt arrow vetical
    584 - golden arrow horizontal | 728 - golden arrow vetical
    576 - iron arrow   horizontal | 720 - iron arrow   vetical

    568 - fireball horizontal     | 712 - fireball vetical
    560 - iceball  horizontal     | 704 - iceball  vetical
    552 - gemball  horizontal     | 696 - gemball  vetical
    */

    i32 sprite_offset_horizontal = 552;
    i32 sprite_offset_vetical = 696;

    switch (_archer->facing) {
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
