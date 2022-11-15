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

#endif
