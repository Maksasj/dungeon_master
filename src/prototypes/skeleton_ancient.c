#include "../include/prototypes/skeleton_ancient.h"

void skeletonAncientUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    i8 direction = _world->grid.vertices[world_position.x][world_position.y];

    _self->vel.x *= 0.6;
    _self->vel.y *= 0.6;

    switch (direction)
    {
        case 'u': //Up
            _self->vel.y += 0.5;
            _self->facing = UP;
            break;
        case 'r': //Right
            _self->vel.x += 0.5;
            _self->facing = RIGHT;
            break;
        case 'd': //Down
            _self->vel.y -= 0.5;
            _self->facing = DOWN;
            break;
        case 'l': //Left
            _self->vel.x -= 0.5;
            _self->facing = LEFT;
            break;
        default:
            break;
    }

    if (world_position.x < 0) {
        _self->vel.x = 0;
        ++_self->vel.x;
    } else if (world_position.x > _GRID_LENGTH_) {
        _self->vel.x = 0;
        --_self->vel.x;
    } else if (world_position.y < 0) {
        _self->vel.y = 0;
        ++_self->vel.y;
    } else if (world_position.y > _GRID_HEIGHT_) {
        _self->vel.y = 0;
        --_self->vel.y;
    }

    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;
}

void skeletonAncientKill(Entity* _self) {
    notePlay(NOTE_C, 1);
}

i32 skeletonAncientCalculateDamage() {
    //TODO: calculate damage
    return 1;
}
