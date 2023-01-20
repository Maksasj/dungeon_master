#include "../../../include/entity/prototypes/projectile.h"
#include "../../../include/world/world.h"

const static i32 GRID_LENGTH = 12;
const static i32 GRID_HEIGHT = 7;

void projectileUpdate(Projectile* _self, void* _room_tmp) {
    Room* _room = (Room*) _room_tmp; 

    ivec2 world_position = screenToWorldPosition(_self->position);

    _self->vel.x = _DIV2_(_self->vel.x);
    _self->vel.y = _DIV2_(_self->vel.y);

    if(_self->facing == RIGHT)
        _self->vel.x += 5;
    else if(_self->facing == DOWN)
        _self->vel.y += 5;
    else if(_self->facing == LEFT)
        _self->vel.x -= 5;
    else if(_self->facing == UP)
        _self->vel.y -= 5;
    else
        _self->vel.y -= 5;

    if (world_position.x < 0 || world_position.x > GRID_LENGTH || world_position.y < 0 || world_position.y > GRID_HEIGHT) {
        deleteProjectileFromRoom(_self, _room);
        entityUnloadSprite(_self);
    }

    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;
}

void rotateProjectile(Projectile* _projectile, i32 sprite_offset_horizontal, i32 sprite_offset_vetical) {
    switch (_projectile->facing) {
        case UP:
            spriteSetOffset(_projectile->sprite, sprite_offset_vetical);
            spriteSetVerticalFlip(_projectile->sprite, 1);
            break;
        case RIGHT: 
            spriteSetOffset(_projectile->sprite, sprite_offset_horizontal);
            spriteSetHorizontalFlip(_projectile->sprite, 0);
            break;
        case DOWN:
            spriteSetOffset(_projectile->sprite, sprite_offset_vetical);
            spriteSetVerticalFlip(_projectile->sprite, 0);
            break;
        case LEFT:
            spriteSetOffset(_projectile->sprite, sprite_offset_horizontal);
            spriteSetHorizontalFlip(_projectile->sprite, 1);
            break;
        default:
            break;
    }
}

void destroyProjectile(Projectile* _self) {
    notePlay(NOTE_C, 1);
}
