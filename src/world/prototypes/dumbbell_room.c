#include "../../../include/world/prototypes/dumbbell_room.h"

void dumbbellRoomInit(Room* _self, Entity* _player) {
    _self->type = DUMBBELL_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(96, 48));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(128, 48));
    tryPushEntityToRoom(_self, _SKELETON_NINJA_ENTITY_(16, 64));
    tryPushEntityToRoom(_self, _SKELETON_NINJA_ENTITY_(208, 64));

    Class class = ((PlayerSpecData*) _player->spec)->class;

    if(class == WARRIOR)
        tryPushItemDropToRoom(_self, _SHORT_SWORD_ITEM_DROP_(112, 48));
    else if(class == WIZARD)
        tryPushItemDropToRoom(_self, _GEM_STAFF_ITEM_DROP_(112, 48));
    else if(class == ARCHER)
        tryPushItemDropToRoom(_self, _WOODEN_BOW_ITEM_DROP_(112, 48));

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
    tryPushLightToRoom(_self, (ivec2){.x = 32, .y = 48});
    tryPushLightToRoom(_self, (ivec2){.x = 192, .y = 48});
}

void dumbbellRoomRender(Room* _self, void* _world) {
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

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 3), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 5), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 6), BORDER_UP, WALL);
    
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 3), TORCH_TILE, NONE);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 3), TORCH_TILE, NONE);
}

void dumbbellRoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
