#include "../../../include/entity/prototypes/projectile.h"

const static i32 GRID_LENGTH = 12;
const static i32 GRID_HEIGHT = 7;

void projectileUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    if(_self->spec == NULL) {
        _self->spec = malloc(sizeof(ProjectileSpec));
        ((ProjectileSpec*) _self->spec)->host_facing = RIGHT;
    } else {
        Facing host_facing = ((ProjectileSpec*) _self->spec)->host_facing;

        _self->vel.x *= 0.6;
        _self->vel.y *= 0.6;

        switch (host_facing) {
            case RIGHT: {
                _self->vel.x += 0.5;
                break;
            }
            case DOWN: {
                _self->vel.y += 0.5;
                break;
            }
            case LEFT: {
                _self->vel.x -= 0.5;
                break;
            }
            case UP: {
                _self->vel.y -= 0.5;
                break;
            }
        }

        if (world_position.x < 0 || world_position.x > GRID_LENGTH || world_position.y < 0 || world_position.y > GRID_HEIGHT) {
            killEntity(_self);
        }

        _self->position.x += _self->vel.x;
        _self->position.y += _self->vel.y;
    }
}

Entity projectileInit(fvec2 _position, u32 _sprite_offset) {
    return entityInit(_position, stats(0, 0, 0, 0, 0), _sprite_offset);
}

void destroyProjectile(Entity* _self) {
    //TODO: play sound
    return;
}
