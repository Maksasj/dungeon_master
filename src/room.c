#include "include/world/room.h"
#include "include/world.h"

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

void renderRoom(Room *room) {
    if(room->type == BASIC) {


        memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, _MAP_WIDTH_ * _MAP_HEIGHT_);
    } else {
        //For now we have only basic room
        exit();
    }
}
