#include "../include/prototypes/skeleton_ninja.h"

void skeletonNinjaUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    if (!_self->saw_the_target) {
        if (_world->grid.distance_to_player[world_position.x][world_position.y] > _FIELD_OF_VIEW_RANGE_) {
            return;
        } else if (_world->grid.distance_to_player[world_position.x][world_position.y] <= _FIELD_OF_VIEW_RANGE_ && _world->grid.distance_to_player[world_position.x][world_position.y] != 0){
            _self->saw_the_target = 1;
        }
    }
    
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

void skeletonNinjaKill(Entity* _self) {
    notePlay(NOTE_C, 1);
}

i32 skeletonNinjaCalculateDamage(Entity* _self) {
    i32 strenght = _self->base_stats.strength;
    
    if (strenght < 0) {
        strenght = 0;
    }
    
    return 1 + strenght;
}

i32 skeletonNinjaTryDodge(Entity* _self) {
    u32 random_number = random((u32)_self->position.x * (u32)_self->position.y) % 101;

    if (random_number < _DODGE_CHANCE_FROM_AGILITY_ * _self->base_stats.agility) {
        return 1;
    }

    return 0;
}
