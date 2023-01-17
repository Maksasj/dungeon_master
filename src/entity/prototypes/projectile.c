#include "../../../include/entity/prototypes/projectile.h"

const static i32 GRID_LENGTH = 12;
const static i32 GRID_HEIGHT = 7;

Entity projectileInit(ivec2 _position, LayerMask _layer, u32 _sprite_offset) {
    return entityInit(_position, stats(0, 0, 0, 0, 0), _layer, _sprite_offset);
}

void projectileUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToWorldPosition(_self->position);

    _self->vel.x /= 2;
    _self->vel.y /= 2;

    switch (_self->facing) {
        case RIGHT: {
            _self->vel.x += 6;
            break;
        }
        case DOWN: {
            _self->vel.y += 6;
            break;
        }
        case LEFT: {
            _self->vel.x -= 6;
            break;
        }
        case UP: {
            _self->vel.y -= 6;
            break;
        } default: {
            _self->vel.y -= 6;
            break;
        }
    }

    if (world_position.x < 0 || world_position.x > GRID_LENGTH || world_position.y < 0 || world_position.y > GRID_HEIGHT) {
        deleteProjectileFromRoom(_self, _room);
        entityUnloadSprite(_self);
    }

    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;
}

void destroyProjectile(Entity* _self) {
    notePlay(NOTE_C, 1);
}
