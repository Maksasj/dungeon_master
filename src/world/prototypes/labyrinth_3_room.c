#include "../../../include/world/prototypes/labyrinth_3_room.h"

void labyrinth3RoomInit(Room* _self, Entity* _player) {
    _self->type = LABYRINTH_3_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    Class class = ((PlayerSpecData*) _player->spec)->class;

    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(192, 32));
    tryPushEntityToRoom(_self, _SKELETON_ANCIENT_ENTITY_(80, 64));
    tryPushEntityToRoom(_self, _SKELETON_NINJA_ENTITY_(48, 32));
    tryPushEntityToRoom(_self, _SKELETON_NINJA_ENTITY_(160, 64));
    tryPushEntityToRoom(_self, _SKELETON_KING_ENTITY_(16, 80));

    if(class == WARRIOR) {
        tryPushItemDropToRoom(_self, _ICE_SWORD_ITEM_DROP_(80, 16));
        tryPushItemDropToRoom(_self, _GOLDEN_CHESTPLATE_ITEM_DROP_(160, 16));
    } else if(class == WIZARD) {
        tryPushItemDropToRoom(_self, _FIRE_STAFF_ITEM_DROP_(80, 16));
        tryPushItemDropToRoom(_self, _RED_MAGE_ARMOR_ITEM_DROP_(160, 16));
    } else if(class == ARCHER) {
        tryPushItemDropToRoom(_self, _AQUA_BOW_ITEM_DROP_(80, 16));
        tryPushItemDropToRoom(_self, _ARCHER_GOLDEN_ARMOR_ITEM_DROP_(160, 16));
    }

    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
    tryPushLightToRoom(_self, (ivec2){.x = 16, .y = 128});
    tryPushLightToRoom(_self, (ivec2){.x = 208, .y = 112});
}

void labyrinth3RoomRender(Room* _self, void* _world) {
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

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 1), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 1), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 2), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 2), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 3), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 3), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 4), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 5), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 5), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(3, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 6), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 6), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 7), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(5, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(9, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(11, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 8), BORDER_UP, WALL);

    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(1, 8), TORCH_TILE, NONE);
    placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(13, 7), TORCH_TILE, NONE);
}

void labyrinth3RoomUpdateCallback(void* _world, Room* _self, Entity* _player) {
    //Lets open room if entity count == 0
    if(_self->current_entity_count == 0) {
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 0), DOOR_UP_OPENED, OPENED_DOOR);
        placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(7, 9), DOOR_BOTTOM_OPENED, OPENED_DOOR);
    }
}
