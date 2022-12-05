#include "../../include/entity/prototypes/necromancer.h"

void necromancerUpdate(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToGridPosition(_self->position);

    static const i32 GRID_LENGTH = 12;
    static const i32 GRID_HEIGHT = 7;
    static const u32 FIELD_OF_VIEW_RANGE = 7;

    if (!_self->saw_the_target) {
        if (_world->grid.distance_to_player[world_position.x][world_position.y] > FIELD_OF_VIEW_RANGE) {
            return;
        } else if (_world->grid.distance_to_player[world_position.x][world_position.y] <= FIELD_OF_VIEW_RANGE && _world->grid.distance_to_player[world_position.x][world_position.y] != 0){
            _self->saw_the_target = 1;
        }
    }

    i8 direction = _world->grid.vertices[world_position.x][world_position.y];

    _self->vel.x *= 0.6;
    _self->vel.y *= 0.6;

    switch (direction)
    {
        case 'u': //Up
            if (world_position.y - 1 >= 0) {
                _self->vel.y -= 0.5;
                _self->facing = UP;
            } else if (world_position.x + 1 <= GRID_LENGTH){
                _self->vel.x += 0.5;
                _self->facing = RIGHT;
            }
            break;
        case 'r': //Right
            if (world_position.x - 1 >= 0) {
                _self->vel.x -= 0.5;
                _self->facing = LEFT;
            } else if (world_position.y - 1 >= 0) {
                _self->vel.y -= 0.5;
                _self->facing = UP;
            }
            break;
        case 'd': //Down
            if (world_position.y + 1 <= GRID_HEIGHT) {
                _self->vel.y += 0.5;
                _self->facing = DOWN;
            } else if (world_position.x - 1 >= 0){
                _self->vel.x -= 0.5;
                _self->facing = LEFT;
            }
            break;
        case 'l': //Left
            if (world_position.x + 1 <= GRID_LENGTH) {
                _self->vel.x += 0.5;
                _self->facing = RIGHT;
            } else if (world_position.y + 1 <= GRID_HEIGHT) {
                _self->vel.y += 0.5;   
                _self->facing = DOWN;
            }
            break;
        default:
            break;
    }

    if (world_position.x < 0) {
        _self->vel.x = 0;
        ++_self->vel.x;
    } else if (world_position.x > GRID_LENGTH) {
        _self->vel.x = 0;
        --_self->vel.x;
    } else if (world_position.y < 0) {
        _self->vel.y = 0;
        ++_self->vel.y;
    } else if (world_position.y > GRID_HEIGHT) {
        _self->vel.y = 0;
        --_self->vel.y;
    }

    _self->position.x += _self->vel.x;
    _self->position.y += _self->vel.y;

    /*
    if(_self->spec == NULL) {
        _self->spec = malloc(sizeof(NecromancerSpec));
        ((NecromancerSpec*) _self->spec)->summonCooldown = 0;
    } else {
        i32 summonCooldown = ((NecromancerSpec*) _self->spec)->summonCooldown;
        if (summonCooldown < 400) {
            ++summonCooldown;
        } else
            summonCooldown = 0;

        ((NecromancerSpec*) _self->spec)->summonCooldown = summonCooldown;

        if(summonCooldown == 0) {
            tryPushEntityToRoom(_room, _SKELETON_ANCIENT_ENTITY_(_self->position.x, _self->position.y));
        }
    }
    */
}

void necromancerKill(Entity* _self) {
    notePlay(NOTE_C, 1);
}

i32 necromancerCalculateDamage(Entity* _self) {
    i32 strenght = _self->base_stats.strength;
    
    if (strenght < 0) {
        strenght = 0;
    }
    
    return 1 + strenght;
}

i32 necromancerTryDodge(Entity* _self) {
    u32 random_number = random((u32)_self->position.x * (u32)_self->position.y) % 101;

    if (random_number < _DODGE_CHANCE_FROM_AGILITY_ * _self->base_stats.agility) {
        return 1;
    }

    return 0;
}
