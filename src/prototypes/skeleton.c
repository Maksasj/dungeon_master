#include "../include/prototypes/skeleton.h"

void skeleton_update(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);
    char direction = _world->grid->vertices[world_position.x][world_position.y];

    switch (direction)
    {
        case 'u': //Up
            _self->position.y += 0.5;
            break;
        case 'r': //Right
            _self->position.x += 0.5;
            break;
        case 'd': //Down
            _self->position.y -= 0.5;
            break;
        case 'l': //Left
            _self->position.x -= 0.5;
            break;

        default:
            break;
    }
}
