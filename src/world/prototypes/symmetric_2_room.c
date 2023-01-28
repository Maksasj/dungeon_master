#include "../../../include/world/prototypes/symmetric_2_room.h"

void symmetric2RoomInit(Room* _self) {
    _self->type = SYMMETRIC_2_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(16, 48));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(176, 32));
    tryPushEntityToRoom(_self, _SKELETON_NINJA_ENTITY_(112, 48));

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
}

void symmetric2RoomRender(Room* _self, void* _world) {
    i32 i; i32 j;

    for(i = 0; i < 15; ++i)
        for(j = 0; j < 10; ++j)
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(i, j), FLOOR_1, NONE);

    for(i = 0; i < 15; ++i) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(i, 9), BORDER_BOTTOM, WALL);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(i, 0), BORDER_UP, WALL);
    }

    for(i = 0; i < 9; ++i) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, i), BORDER_RIGHT, WALL);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(0, i), BORDER_LEFT, WALL);
    }
   
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(0, 0), CORNER_LEFT_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), CORNER_RIGHT_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(0, 9), CORNER_LEFT_BOTTOM, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 9), CORNER_RIGHT_BOTTOM, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 2), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 3), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 5), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 6), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 7), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 8), BIG_SPIKES_TILE, TRAP);
}

void symmetric2RoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
