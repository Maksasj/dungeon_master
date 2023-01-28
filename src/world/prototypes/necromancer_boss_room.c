#include "../../../include/world/prototypes/necromancer_boss_room.h"

void necromancerBossRoomInit(Room* _self) {
    _self->type = NECROMANCER_BOSS_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushEntityToRoom(_self, _NECROMANCER_ENTITY_(112, 64));

    tryPushLightToRoom(_self, (ivec2){.x = 64, .y = 64});
    tryPushLightToRoom(_self, (ivec2){.x = 176, .y = 64});
}

void necromancerBossRoomRender(Room* _self, void* _world) {
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
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 3), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 3), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 4), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 5), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), LAVA_BIG_TILE, TRAP);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 6), LAVA_BIG_TILE, TRAP);
}

void necromancerBossRoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
