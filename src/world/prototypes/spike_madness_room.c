#include "../../../include/world/prototypes/spike_madness_room.h"

void spikeMadnessRoomInit(Room* _self) {
    _self->type = SPIKE_MADNESS_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(48, 32));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(176, 48));

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
}

void spikeMadnessRoomRender(Room* _self, void* _world) {
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

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2,  1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3,  1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4,  1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 1), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  2), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 2), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  3), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 3), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 4), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 4), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 5), BIG_SPIKES_TILE, TRAP);
    
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  6), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 6), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  7), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 7), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1,  8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2,  8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3,  8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4,  8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 8), BIG_SPIKES_TILE, TRAP);
}

void spikeMadnessRoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
