#include "include/world/room.h"
#include "include/world.h"

#include "include/world/tile.h"

#include "assets/map.h"

u8 collisionCallBack(Room *room, ivec2 pos) {
    if(room->type == BASIC) {
        // TODO

        if(pos.x < 4) return 1;
        if(pos.y < 4) return 1;
        if(pos.y > 136) return 1;
        if(pos.x > 220) return 1;

        return 0;
    } else {
        //For now we have only basic room
        exit();
    }

    return 0;
}

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

void placeTile(u16* target, ivec2 pos, const u16* tile) {
    target[pos.x + pos.y * 32] = tile[0];
    target[pos.x + pos.y * 32 + 1] = tile[1];
    target[pos.x + pos.y * 32 + 32] = tile[2];
    target[pos.x + pos.y * 32 + 33] = tile[3];
}

void loadBasicRoom(u16* target) {
    int i; int j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(MAP, newIVec2(i*2, j*2), getRandomFloorTile());
        }
    }

    for(i = 0; i < 15; ++i) {
        placeTile(MAP, newIVec2(i*2, 18), BORDER_BOTTOM);
        placeTile(MAP, newIVec2(i*2, 0), BORDER_UP);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(MAP, newIVec2(28, i*2), BORDER_RIGHT);
        placeTile(MAP, newIVec2(0, i*2), BORDER_LEFT);
    }

   
    placeTile(MAP, newIVec2(0, 0), CORNER_LEFT_UP);
    placeTile(MAP, newIVec2(28, 0), CORNER_RIGHT_UP);
    placeTile(MAP, newIVec2(0, 18), CORNER_LEFT_BOTTOM);
    placeTile(MAP, newIVec2(28, 18), CORNER_RIGHT_BOTTOM);


    placeTile(MAP, newIVec2(14, 0), DOOR_UP_OPENED);
    //placeTile(MAP, newIVec2(14, 18), DOO);

    /*
    placeTile(MAP, newIVec2(2, 8), DOOR_UP_CLOSED);
    placeTile(MAP, newIVec2(4, 8), DOOR_UP_OPENED);
    placeTile(MAP, newIVec2(6, 8), DOOR_RIGHT_CLOSED);
    placeTile(MAP, newIVec2(8, 8), DOOR_LEFT_CLOSED);
    placeTile(MAP, newIVec2(10, 8), DOOR_BOTTOM_CLOSED);
    */
}

void renderRoom(Room *room) {
    if(room->type == BASIC) {
        loadBasicRoom(MAP);
    } else {
        //For now we have only basic room
        exit();
    }

    memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
}
