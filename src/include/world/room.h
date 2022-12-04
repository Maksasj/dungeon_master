#ifndef _ROOM_H_
#define _ROOM_H_

#include "../types.h"
#include "../collision.h"
#include "../entity/entity.h"

#include "../item.h"

#define _MAX_ENTITY_PER_ROOM_ 5
#define _MAX_ITEM_DROP_PER_ROOM_ 10

typedef enum RoomType {
    BASIC,
    TWO_NINJA_SKELETONS_ENEMIES,
    TWO_NINJA_SKELETONS_ENEMIES1,
    TWO_NINJA_SKELETONS_ENEMIES2,
    TWO_NINJA_SKELETONS_ENEMIES3,
    TWO_NINJA_SKELETONS_ENEMIES4,
    END,
} RoomType;

typedef struct Room {
    RoomType type;

    Entity entity_pool[_MAX_ENTITY_PER_ROOM_];
    i32 current_entity_count;

    ItemDrop itemdrop_pool[_MAX_ITEM_DROP_PER_ROOM_];
    i32 current_itemdrop_count;
    
    /* TODO
    Projectile pool

    Update callback
    */
} Room;

void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index);

void tryPushEntityToRoom(Room* _room, Entity _entity);

void tryPushItemDropToRoom(Room* _room, ItemDrop _itemdrop);

void deleteEntityFromRoom(Entity* _entity, Room* _room);

void unLockRoom(void* _world, Room* _room);

#endif
