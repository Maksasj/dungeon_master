#ifndef _ROOM_H_
#define _ROOM_H_

#include "../utils/types.h"
#include "../collision.h"
#include "../entity/entity.h"
#include "../light.h"

#include "../item.h"

#define _MAX_ENTITY_PER_ROOM_ 5
#define _MAX_PROJECTILE_PER_ROOM_ 1
#define _MAX_ITEM_DROP_PER_ROOM_ 10
#define _MAX_LIGHT_COUNT_ 5

typedef enum RoomType {
    BASIC,
    TWO_NINJA_SKELETONS_ENEMIES,
    FOUR_ANCIENT_SKELETONS,
    LABYRINTH1,
    LABYRINTH2,
    LABYRINTH3,
    ANCIENT,
    DUMBBELL,
    SYMMETRIC,
    CORRIDORS,
    KING_IN_CORRIDOR,
    PAC_MAN,
    PYRAMID,
    FLOOR_END,
    END_GAME
} RoomType;

typedef struct Room {
    RoomType type;

    Entity entity_pool[_MAX_ENTITY_PER_ROOM_];
    i32 current_entity_count;

    Entity projectile_pool[_MAX_PROJECTILE_PER_ROOM_];
    i32 current_projectile_count;

    ItemDrop itemdrop_pool[_MAX_ITEM_DROP_PER_ROOM_];
    i32 current_itemdrop_count;

    ivec2 lights[_MAX_LIGHT_COUNT_];
    i32 current_light_count;
} Room;

void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index);

void tryPushLightToRoom(Room *_room, ivec2 pos);

void tryPushEntityToRoom(Room* _room, Entity _entity);

void tryPushProjectileToRoom(Room* _room, Entity _projectile);

void tryPushItemDropToRoom(Room* _room, ItemDrop _itemdrop);

void deleteEntityFromRoom(Entity* _entity, Room* _room);

void deleteProjectileFromRoom(Entity* _projectile, Room* _room);

void unLockRoom(void* _world, Room* _room);

#endif
