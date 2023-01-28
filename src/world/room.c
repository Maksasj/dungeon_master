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
