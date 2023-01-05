#include "../../include/world/room.h"
#include "../../include/world/world.h"

#include "../../include/world/tile.h"

const u16* getRandomFloorTile() {
    u16 value = rand() % 6;

    switch (value) {
        case 0:
            return FLOOR_1;
        case 1:
            return FLOOR_2;
        case 2:
            return FLOOR_3;
        case 3:
            return FLOOR_4;
        case 4:
            return FLOOR_5;
        case 5:
            return FLOOR_6;
        default:
            break;
    }

    return FLOOR_3;
}

void placeTile(World* _world, u16* _target, ivec2 _pos, const u16* _tile, CollisionType _collision_type) {
    _target[_pos.x + _pos.y * 32] = _tile[0];
    _target[_pos.x + _pos.y * 32 + 1] = _tile[1];
    _target[_pos.x + _pos.y * 32 + 32] = _tile[2];
    _target[_pos.x + _pos.y * 32 + 33] = _tile[3];

    switch(_collision_type) {
        case WALL: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = '#';
            break;
        }
        case OPENED_DOOR: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'D';
            break;
        }
        case CLOSED_DOOR: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'C';
            break;
        }
        case CHEST: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'X';
            break;
        }
        case NEXT_FLOOR_ENTRANCE: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = 'E';
            break;
        }
        default: {
            _world->collision_box[_pos.y / 2][_pos.x / 2] = ' ';
            break;
        }
    }
}

void loadBasicRoom(World* _world, u16* _target) {
    i32 i;
    i32 j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(_world, _world->MAP, newIVec2(i*2, j*2), getRandomFloorTile(), NONE);
        }
    }

    for(i = 0; i < 15; ++i) {
        placeTile(_world, _world->MAP, newIVec2(i*2, 18), BORDER_BOTTOM, WALL);
        placeTile(_world, _world->MAP, newIVec2(i*2, 0), BORDER_UP, WALL);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(_world, _world->MAP, newIVec2(28, i*2), BORDER_RIGHT, WALL);
        placeTile(_world, _world->MAP, newIVec2(0, i*2), BORDER_LEFT, WALL);
    }
   
    placeTile(_world, _world->MAP, newIVec2(0, 0), CORNER_LEFT_UP, WALL);
    placeTile(_world, _world->MAP, newIVec2(28, 0), CORNER_RIGHT_UP, WALL);
    placeTile(_world, _world->MAP, newIVec2(0, 18), CORNER_LEFT_BOTTOM, WALL);
    placeTile(_world, _world->MAP, newIVec2(28, 18), CORNER_RIGHT_BOTTOM, WALL);

    //placeTile(_world, _world->MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
}

void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index) {
    loadBasicRoom(_world, (u16*) (((World*) _world)->MAP));

    i32 i;

    switch (_room->type) {
        case BASIC: {
            placeTile(_world, ((World*) _world)->MAP, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
            break;
        }
        case TWO_NINJA_SKELETONS_ENEMIES: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 10), BORDER_UP, WALL);
            break;
        }
        case FOUR_ANCIENT_SKELETONS: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            break;
        }
        case ONE_NINJA_THREE_ANCIENT: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            break;
        }
        case THREE_KINGS: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            break;
        }
        case NECROMANCER_TWO_KINGS: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            break;
        }
        case LABYRINTH1: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 2), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 2), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 4), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 6), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 12), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 14), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 16), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 16), BORDER_UP, WALL);

            break;
        }
        case LABYRINTH2: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 4), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 6), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 8), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 12), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 14), BORDER_UP, WALL);

            break;
        }
        case ANCIENT: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 6), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 12), BORDER_UP, WALL);

            break;
        }
        case DUMBBELL: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 6), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 12), BORDER_UP, WALL);

            break;
        }
        case SYMMETRIC: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 2), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 2), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 2), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 2), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 4), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 4), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 6), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 8), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(20, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 12), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 14), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 14), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 16), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(4, 16), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(24, 16), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 16), BORDER_UP, WALL);

            break;
        }
        case CORRIDORS: {
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 6), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 6), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 8), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 10), BORDER_UP, WALL);

            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(2, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(22, 12), BORDER_UP, WALL);
            placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(26, 12), BORDER_UP, WALL);

            break;
        }
        case FLOOR_END: {
            placeTile(_world, ((World*)_world)->MAP, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);
            placeTile(_world, ((World*)_world)->MAP, newIVec2(14, 8), DOOR_UP_OPENED, NEXT_FLOOR_ENTRANCE);
            break;  
        }
        case END_GAME: {
            placeTile(_world, ((World*)_world)->MAP, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);
            break;
        }
    }

    for(i = 0; i < _room->current_entity_count; ++i) {
        Entity* entity = &_room->entity_pool[i];
        entityInitSprite(entity, _sprites, _next_sprite_index);
        spriteSetOffset(entity->sprite, entity->sprite_offset);
    }

    for(i = 0; i < _room->current_itemdrop_count; ++i) {
        ItemDrop* _itemdrop = &_room->itemdrop_pool[i];

        itemDropInitSprite(_itemdrop, _sprites, _next_sprite_index);
        spriteSetOffset(_itemdrop->sprite, _itemdrop->sprite_offset);
    }

    memcpy16DMA((u16*) screenBlock(13), (u16*) (((World*) _world)->MAP), 32 * 32);
}

void tryPushEntityToRoom(Room* _room, Entity _entity) {
    if (_room->current_entity_count < _MAX_ENTITY_PER_ROOM_) {
        _room->entity_pool[_room->current_entity_count] = _entity;
        ++_room->current_entity_count;
    }
}

void tryPushItemDropToRoom(Room* _room, ItemDrop _itemdrop) {
    if (_room->current_itemdrop_count < _MAX_ITEM_DROP_PER_ROOM_) {
        _room->itemdrop_pool[_room->current_itemdrop_count] = _itemdrop;
        ++_room->current_itemdrop_count;
    }
}

void unLockRoom(void* _world, Room* _room) {
    placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
    placeTile(_world, (u16*) (((World*) _world)->MAP), newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);

    memcpy16DMA((u16*) screenBlock(13), (u16*) (((World*) _world)->MAP), 32 * 32);
}

void deleteEntityFromRoom(Entity* _entity, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_entity_count; ++i) {
        if (_entity == &_room->entity_pool[i]) {
            for (j = i + 1; j < _room->current_entity_count; ++j) {
                _room->entity_pool[i] = _room->entity_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_entity_count;
}


void deleteItemDropFromRoom(ItemDrop* _entity, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_itemdrop_count; ++i) {
        if (_entity == &_room->itemdrop_pool[i]) {
            for (j = i + 1; j < _room->current_itemdrop_count; ++j) {
                _room->itemdrop_pool[i] = _room->itemdrop_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_itemdrop_count;
}
