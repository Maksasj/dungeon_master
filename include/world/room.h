/**
 * Room
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains all needed functions and structures for work with rooms
*/

#ifndef _ROOM_H_
#define _ROOM_H_

#include "../utils/types.h"
#include "../collision.h"
#include "../entity/entity.h"
#include "../entity/prototypes/projectile.h"
#include "../light.h"

#include "../item/item.h"

/* Constant that limits entity count per single room */
#define _MAX_ENTITY_PER_ROOM_ 5

/* Constant that limits projectile count per single room */
#define _MAX_PROJECTILE_PER_ROOM_ 20

/* Constant that limits item drop count per single room */
#define _MAX_ITEM_DROP_PER_ROOM_ 10

/* Constant that limits light count per single room */
#define _MAX_LIGHT_COUNT_ 5

/* Enum that contains all currently available rooms in game */
typedef enum RoomType {
    BASIC,
    TWO_NINJA_SKELETONS_ENEMIES,
    FOUR_ANCIENT_SKELETONS,
    LABYRINTH1,
    LABYRINTH2,
    LABYRINTH3,
    DARK_LABYRINTH,
    ANCIENT,
    DUMBBELL,
    SYMMETRIC1,
    SYMMETRIC2,
    CORRIDORS,
    KING_IN_CORRIDOR,
    PAC_MAN,
    PYRAMID,
    SPIKE_MADNESS,
    BOSS,
    FLOOR_END,
    END_GAME
} RoomType;

/* Structure that contains all needed information to discribe room */
typedef struct Room {
    /* Type of the room */
    RoomType type;

    /* Entity pool, basically array that contains all entities */
    Entity entity_pool[_MAX_ENTITY_PER_ROOM_];
    i32 current_entity_count;

    /* ItemDrop pool, basically array that contains all item drops */
    ItemDrop itemdrop_pool[_MAX_ITEM_DROP_PER_ROOM_];
    i32 current_itemdrop_count;

    /* Light pool, basically array that contains all lights */
    ivec2 lights[_MAX_LIGHT_COUNT_];
    i32 current_light_count;

    /* Projectile pool, basically array that contains all projectiles */
    Projectile projectile_pool[_MAX_PROJECTILE_PER_ROOM_];                          
    i32 current_projectile_count;                           
    //Entity projectile_pool1[_MAX_PROJECTILE_PER_ROOM_];                         
} Room;

void initRoom(Room* _room);

/**
 * Renders room to the screen
 * 
 * @param   _world  Pointer to main world structure (This structure should contain this room)
 * @param   _room Pointer to room it self
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index   
*/
void renderRoom(void* _world, Room* _room, Sprite* _sprites, i32* _next_sprite_index);

/**
 * Tries to push light to the room
 * 
 * @param   _room Pointer to room it self
 * @param   _pos Position of the new light
*/
void tryPushLightToRoom(Room *_room, ivec2 _pos);

/**
 * Tries to push entity to the room
 * 
 * @param   _room Pointer to room it self
 * @param   _entity New entity
*/
int tryPushEntityToRoom(Room* _room, Entity _entity);

/**
 * Tries to push projectile to the room
 * 
 * @param   _room Pointer to room it self
 * @param   _projectile New projectile
*/
void tryPushProjectileToRoom(Room* _room, Projectile _projectile);

/**
 * Tries to push item drop to the room
 * 
 * @param   _room Pointer to room it self
 * @param   _itemdrop New item drop
*/
void tryPushItemDropToRoom(Room* _room, ItemDrop _itemdrop);

/**
 * Deletes entity from the room
 * 
 * @param   _entity Pointer to entity that should be deleted
 * @param   _room Pointer to the room wich cotains listed entity
*/
void deleteEntityFromRoom(Entity* _entity, Room* _room);

/**
 * Deletes projectile from the room
 * 
 * @param   _projectile Pointer to entity that should be deleted
 * @param   _room Pointer to the room wich cotains listed projectile
*/
void deleteProjectileFromRoom(Entity* _projectile, Room* _room);

/**
 * Unlocks room, basically changes a fiew tiles
 * 
 * @param   _world Pointer to world structure
 * @param   _room Pointer to the room
*/
void unLockRoom(void* _world, Room* _room);

void loadTmpEntitySprite(Room* _room);

void loadTmpItemDropSprite(Room* _room);

#endif
