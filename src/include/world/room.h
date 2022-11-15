#ifndef _ROOM_H_
#define _ROOM_H_

#include "../types.h"

typedef enum ROOM_TYPE {
    BASIC,
} ROOM_TYPE;

typedef struct Room {
    ROOM_TYPE type;
} Room;

void renderRoom(Room *room);

vu16* charBlock(u32 _block);

vu16* screenBlock(u32 _block);

#endif
