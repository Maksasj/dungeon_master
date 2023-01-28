#include "../../../include/world/prototypes/four_ancient_skeleton_room.h"

void fourAncientSkeletonRoomInit(Room* _self, Entity* _player) {
    _self->type = FOUR_ANCIENT_SKELETON_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(48, 64));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(80, 48));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(144, 48));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(176, 64));

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
    tryPushLightToRoom(_self, (ivec2){.x = 160, .y = 80});
    tryPushLightToRoom(_self, (ivec2){.x = 64, .y = 80});
}

void fourAncientSkeletonRoomRender(Room* _self, void* _world) {
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

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 1), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 3), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 3), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 5), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 7), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 7), BIG_SPIKES_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BIG_SPIKES_TILE, TRAP);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 5), TORCH_TILE, NONE);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), TORCH_TILE, NONE);
}

void fourAncientSkeletonRoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
