#include "../../../include/entity/prototypes/projectile.h"

const static i32 GRID_LENGTH = 12;
const static i32 GRID_HEIGHT = 7;

Entity projectileInit(fvec2 _position, LayerMask _layer, u32 _sprite_offset) {
    return entityInit(_position, stats(1, 0, 0, 0, 0), _layer, _sprite_offset);
}

void projectileUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    _self->vel.x *= 0.6;
    _self->vel.y *= 0.6;

    switch (_self->facing) {
        case RIGHT: {
            _self->vel.x += 0.25;
            break;
        }
        case DOWN: {
            _self->vel.y += 0.25;
            break;
        }
        case LEFT: {
            _self->vel.x -= 0.25;
            break;
        }
        case UP: {
            _self->vel.y -= 0.25;
            break;
        }
    }

    if (world_position.x < 0 || world_position.x > GRID_LENGTH || world_position.y < 0 || world_position.y > GRID_HEIGHT) {
        _self->health = 0;
        destroyProjectile(_self);
    }

    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;
}

i32 projectileCalculateDamage(Entity* _self) {
    return 1;
}

void destroyProjectile(Entity* _self) {
    entityUnloadSprite(_self);
    //TODO: play sound
    return;
}
