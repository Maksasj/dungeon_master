#include "include/world/room.h"
#include "include/world.h"

#include "include/world/tile.h"

#include "assets/map.h"

u8 collisionCallBack(Room *room, ivec2 pos) {
    if(room->type == BASIC) {
        // TODO

        if(pos.x < 15) return 1;
        if(pos.y < 15) return 1;
        if(pos.y > 150) return 1;
        if(pos.x > 150) return 1;

        return 0;
    } else {
        //For now we have only basic room
        exit();
    }
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

void renderRoom(Room *room) {
    int i;
    int j;
    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            placeTile(MAP, newIVec2(i*2, j*2), getRandomFloorTile());
        }
    }

    if(room->type == BASIC) {
        memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
    } else {
        //For now we have only basic room
        exit();
    }
}
