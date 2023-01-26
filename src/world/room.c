#include "../../include/world/room.h"
#include "../../include/world/room_macros.h"

static void* _SPRITES_POINTER_;
static void* _NEXT_SPRITE_INDEX_;

/*
const u16* getRandomFloorTile() {
    u16 value = rand() % 6;

    switch (value) {
        case 0:
            return FLOOR_1;
        case 1:
            return FLOOR_2;
        case 2:
            return FLOOR_3;
        case 3:
            return FLOOR_4;
        case 4:
            return FLOOR_5;
        case 5:
            return FLOOR_6;
        default:
            break;
    }

    return FLOOR_3;
}
*/

void initRoom(Room* _room) {
    _room->type = FLOOR_BEGINNING_ROOM;

    _room->current_entity_count = 0;
    _room->current_itemdrop_count = 0;
    _room->current_light_count = 0;
    _room->current_projectile_count = 0;
}

/*
const u16* getRandomLavaTile() {
    u16 value = rand() % 2;

    switch (value) {
        case 0:
            return LAVA_TILE;
        case 1:
            return LAVA_BIG_TILE;
    }

    return FLOOR_3;
}
*/

void loadTmpEntitySprite(Room* _room) {
    entityInitSprite(&_room->entity_pool[_room->current_entity_count - 1], _SPRITES_POINTER_, _NEXT_SPRITE_INDEX_);
}

void loadTmpItemDropSprite(Room* _room) {
    itemDropInitSprite(&_room->itemdrop_pool[_room->current_itemdrop_count - 1], _SPRITES_POINTER_, _NEXT_SPRITE_INDEX_);
}

void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index) {
    _SPRITES_POINTER_= _sprites;
    _NEXT_SPRITE_INDEX_ = _next_sprite_index;

    ROOM_PROTOTYPES_RENDER_CALLBACKS[_room->type](_room, _world);
    

    //loadBasicRoom(_world, TILE_BACKGROUND_SCREEN_BLOCK);

    /*
    switch (_room->type) {
        case BASIC: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_OPENED, OPENED_DOOR);
            break;
        }
        case TWO_NINJA_SKELETONS_ENEMIES: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BIG_SPIKES_TILE, TRAP);
            break;
        }
        case FOUR_ANCIENT_SKELETONS: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 6), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 6), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 14), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 14), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 16), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), TORCH_TILE, NONE);
            break;
        }
        case LABYRINTH1: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 16), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 4), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 14), TORCH_TILE, NONE);
            break;
        }
        case LABYRINTH2: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 10), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 8), TORCH_TILE, NONE);
            break;
        }
        case LABYRINTH3: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 16), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 16), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 14), TORCH_TILE, NONE);
            break;
        }
        case DARK_LABYRINTH: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 16), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 16), BIG_SPIKES_TILE, TRAP);
            break;
        }
        case ANCIENT: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);
            break;
        }
        case DUMBBELL: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 6), TORCH_TILE, NONE);
            break;
        }
        case SYMMETRIC1: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 16), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), TORCH_TILE, NONE);
            break;
        }
        case SYMMETRIC2: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 16), BIG_SPIKES_TILE, TRAP);
            break;
        }
        case CORRIDORS: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 12), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 4), TORCH_TILE, NONE);
            break;
        }
        case KING_IN_CORRIDOR: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 12), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), TORCH_TILE, NONE);
            break;
        }
        case PAC_MAN: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 12), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 14), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 14), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 16), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 16), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 14), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 14), TORCH_TILE, NONE);
            break;
        }
        case PYRAMID: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 2), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 4), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 4), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 6), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 8), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 10), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 10), BORDER_UP, WALL);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 12), BORDER_UP, WALL);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 12), BORDER_UP, WALL);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 10), TORCH_TILE, NONE);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), TORCH_TILE, NONE);
            break;
        }
        case SPIKE_MADNESS: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 2), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 2), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 4), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 4), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 6), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 6), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 8), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 8), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(12, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(16, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 10), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 10), BIG_SPIKES_TILE, TRAP);
            
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 12), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 12), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 14), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 14), BIG_SPIKES_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(2, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(4, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(6, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(10, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(18, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(20, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(24, 16), BIG_SPIKES_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(26, 16), BIG_SPIKES_TILE, TRAP);
            break;
        }
        case BOSS: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 0), DOOR_UP_CLOSED, CLOSED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_CLOSED, CLOSED_DOOR);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 6), LAVA_BIG_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 6), LAVA_BIG_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 8), LAVA_BIG_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 8), LAVA_BIG_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 10), LAVA_BIG_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 10), LAVA_BIG_TILE, TRAP);

            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(8, 12), LAVA_BIG_TILE, TRAP);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(22, 12), LAVA_BIG_TILE, TRAP);
            break;
        }
        case FLOOR_END: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 8), DOOR_UP_OPENED, NEXT_FLOOR_ENTRANCE);
            break;  
        }
        case END_GAME: {
            placeTile(_world, TILE_BACKGROUND_SCREEN_BLOCK, newIVec2(14, 18), DOOR_BOTTOM_OPENED, OPENED_DOOR);
            break;
        }
    }
    */

    i32 i;
    for(i = 0; i < _room->current_entity_count; ++i) {
        Entity* entity = &_room->entity_pool[i];
        entityInitSprite(entity, _sprites, _next_sprite_index);
        spriteSetOffset(entity->sprite, entity->sprite_offset);
    }

    for(i = 0; i < _room->current_itemdrop_count; ++i) {
        ItemDrop* _itemdrop = &_room->itemdrop_pool[i];

        itemDropInitSprite(_itemdrop, _sprites, _next_sprite_index);
        spriteSetOffset(_itemdrop->sprite, _itemdrop->sprite_offset);
    }
}

void tryPushLightToRoom(Room *_room, ivec2 _pos) {
    _pos.x /= 8;
    _pos.y /= 8;

    if (_room->current_light_count < _MAX_LIGHT_COUNT_) {
        _room->lights[_room->current_light_count] = _pos;
        ++_room->current_light_count;
    }
}

int tryPushEntityToRoom(Room* _room, Entity _entity) {
    if (_room->current_entity_count < _MAX_ENTITY_PER_ROOM_) {
        _room->entity_pool[_room->current_entity_count] = _entity;
        ++_room->current_entity_count;
        return 1;
    }

    return 0;
}

void tryPushProjectileToRoom(Room* _room, Projectile _projectile) {
    if (_room->current_projectile_count < _MAX_PROJECTILE_PER_ROOM_) {
        _room->projectile_pool[_room->current_projectile_count] = _projectile;
        ++_room->current_projectile_count;
    }
}

void tryPushItemDropToRoom(Room* _room, ItemDrop _itemdrop) {
    if (_room->current_itemdrop_count < _MAX_ITEM_DROP_PER_ROOM_) {
        _room->itemdrop_pool[_room->current_itemdrop_count] = _itemdrop;
        ++_room->current_itemdrop_count;
    }
}

void deleteEntityFromRoom(Entity* _entity, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_entity_count; ++i) {
        if (_entity == &_room->entity_pool[i]) {
            for (j = i + 1; j < _room->current_entity_count; ++j) {
                _room->entity_pool[i] = _room->entity_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_entity_count;
}

void deleteProjectileFromRoom(Entity* _projectile, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_projectile_count; ++i) {
        if (_projectile == &_room->projectile_pool[i]) {
            for (j = i + 1; j < _room->current_projectile_count; ++j) {
                _room->projectile_pool[i] = _room->projectile_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_projectile_count;
}

void deleteItemDropFromRoom(ItemDrop* _entity, Room* _room) {
    i32 i;
    i32 j;

    for (i = 0; i < _room->current_itemdrop_count; ++i) {
        if (_entity == &_room->itemdrop_pool[i]) {
            for (j = i + 1; j < _room->current_itemdrop_count; ++j) {
                _room->itemdrop_pool[i] = _room->itemdrop_pool[j];
                ++i;
            }

            break;
        }
    }

    --_room->current_itemdrop_count;
}
