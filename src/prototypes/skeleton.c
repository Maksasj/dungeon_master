#include "../include/prototypes/skeleton.h"

static ivec2 PREVIOUS_TILE_POSITION;
static u8 DIRECTION;

void skeleton_update(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    if (PREVIOUS_TILE_POSITION.x != world_position.x || PREVIOUS_TILE_POSITION.y != world_position.y) {
        DIRECTION = _world->grid.vertices[world_position.x][world_position.y];
        PREVIOUS_TILE_POSITION = world_position;
    }

    switch (DIRECTION)
    {
        case 'u': //Up
            _self->position.y += 10;
            break;
        case 'r': //Right
            _self->position.x += 10;
            break;
        case 'd': //Down
            _self->position.y -= 10;
            break;
        case 'l': //Left
            _self->position.x -= 10;
            break;

        default:
            break;
    }
}
