#include "../../../include/world/prototypes/floor_beginning_room.h"

void FloorBeginningRoomInit(Room* _self) {
    _self->type = FLOOR_BEGINNING_ROOM;

    _self->current_entity_count = 0;
    _self->current_itemdrop_count = 0;
    _self->current_projectile_count = 0;
    _self->current_light_count = 0;
    
    tryPushLightToRoom(_self, (ivec2){.x = 112, .y = 0});
}

void FloorBeginningRoomRender(Room* _self) {
    /* gag */
}

void FloorBeginningRoomUpdateCallback(Room* _self, Entity* _player) {
    /* gag */
}
