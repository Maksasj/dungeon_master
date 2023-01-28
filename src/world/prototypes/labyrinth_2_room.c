#include "../../../include/world/prototypes/labyrinth_2_room.h"

void labyrinth2RoomInit(Room* _self, Entity* _player) {
    _self->type = LABYRINTH_2_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    Class class = ((PlayerSpecData*) _player->spec)->class;

    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(96, 16));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(112, 64));
    tryPushEntityToRoom(_self, _SKELETON_NINJA_ENTITY_(208, 48));
    tryPushEntityToRoom(_self, _SKELETON_KING_ENTITY_(32, 128));

    if(class == WARRIOR)
        tryPushItemDropToRoom(_self, _IRON_CHESTPLATE_ITEM_DROP_(16, 32));
    else if(class == WIZARD)
        tryPushItemDropToRoom(_self, _PURPLE_MAGE_ARMOR_ITEM_DROP_(16, 32));
    else if(class == ARCHER)
        tryPushItemDropToRoom(_self, _ARCHER_IRON_ARMOR_ITEM_DROP_(16, 32));

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 80});
    tryPushLightToRoom(_self, (ivec2){.x = 208, .y = 80});
    tryPushLightToRoom(_self, (ivec2){.x = 16, .y = 64});
}

void labyrinth2RoomRender(Room* _self, void* _world) {
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

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 2), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 3), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 4), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 5), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 6), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 7), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 7), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 5), TORCH_TILE, NONE);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 5), TORCH_TILE, NONE);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 4), TORCH_TILE, NONE);
}

void labyrinth2RoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
