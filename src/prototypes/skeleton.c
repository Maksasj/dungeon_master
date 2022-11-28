#include "../include/prototypes/skeleton.h"

void skeleton_update(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    i8 direction = _world->grid.vertices[world_position.x][world_position.y];

    switch (direction)
    {
        case 'u': //Up
            _self->position.y += 1;
            break;
        case 'r': //Right
            _self->position.x += 1;
            break;
        case 'd': //Down
            _self->position.y -= 1;
            break;
        case 'l': //Left
            _self->position.x -= 1;
            break;
        default:
            break;
    }

    /*
    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;

    _self->vel.x = 0;
    _self->vel.y = 0;
    */
}
