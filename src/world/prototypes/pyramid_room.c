#include "../../../include/world/prototypes/pyramid_room.h"

void pyramidRoomInit(Room* _self) {
    _self->type = PYRAMID_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(160, 64));

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
    tryPushLightToRoom(_self, (ivec2){.x = 64, .y = 80});
    tryPushLightToRoom(_self, (ivec2){.x = 160, .y = 80});
}

void pyramidRoomRender(Room* _self, void* _world) {
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
   
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 1), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 1), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 1), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 1), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 5), TORCH_TILE, NONE);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), TORCH_TILE, NONE);
}

void pyramidRoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
