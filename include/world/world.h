/**
 * World
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains all needed functions and structures needed to work with World
*/

#ifndef _WORLD_H_
#define _WORLD_H_

#include "../utils/types.h"
#include "../sprite.h"
#include "../utils/queue.h"
#include "../utils/grid.h"
#include "../utils/logger.h"
#include "../sound/sound.h"

#include "../utils/logger.h"

#include "room.h"

/* Build in cheat, allows to not take damage from any source */
#define _GOD_MODE_

/* Disables all light rendering */
#define _LIGHT_ON_

/* Room count per one dungeon floor */
#define _MAX_ROOM_COUNT_ 5

/* Constant that defines how often should be runned path finding */
#define _BFS_TICK_RATE_ 50


/* Structure that contains all needed information to discribe world */
typedef struct World {
    /* Array of all rooms in single floor */
    Room rooms[_MAX_ROOM_COUNT_];

    /* Contains all needed for path finding */
    SquareGrid grid;

    /* Index of the active room */
    u8 activeRoom;

    /* Amout of floors */
    u8 floorCount;

    /* Index of the current floor */
    u8 currentFloor;
    
    /* Todo */
    u8 difficulty;

    /* Contains all tile, used for rendering purposes */
    u16 MAP[1024];

    /* Tile descriptions
        '#' - Wall
        'D' - Opened Door
        'C' - Closed Door
        'E' - Next Floor Entrance
        'X' - Trap
        ' ' - None
    */

    /* Used for storing all collision boxes */
    u8 collision_box[10][15];
} World;

/* Global variable that determines, if game completed or not*/
extern i32 game_completed;

/**
 * Changes active room, renders new room.,
 * 
 * @param   _world  Pointer to main world structure;
 * @param   _roomId Index of the new room
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index   
*/
void gotoRoom(World* _world, u8 _roomId, Sprite* _sprites, i32* _next_sprite_index);

/**
 * Generates an entire dungeon floor
 * 
 * @param   _world  Pointer to main world structure;
 * @param   _class Player combat class, used to spawn class specified items
*/
void generateFloor(World* _world, i32 _class);

/**
 * Main function to update active room,
 * Updates active room, all entities, projectiles, etc.
 * 
 * @param   _world  Pointer to main world structure;
*/
void updateWorld(World* _world, Entity* _player);

/**
 * Wrapper around gotoRoom function, changes room to next room(activeroom++)
 * 
 * @param   _world  Pointer to main world structure;
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index   
*/
void nextRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index);

/**
 * Wrapper around gotoRoom function, changes room to previouse room(--activeroom)
 * 
 * @param   _world  Pointer to main world structure;
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index   
*/
void backRoom(World* _world, Sprite* _sprites, i32* _next_sprite_index);

/**
 * Function that returns collision of the obstacle in active room and provided positions
 * 
 * @param   _world  Pointer to main world structure;
 * @param   _pos    Possition
 * @return          Type of this collision(NONE, WALL, TRAP, DOOR, etc.)
*/
CollisionType worldCollision(World* _world, ivec2 _pos);

/**
 * Converts provided screen coordinates to grid coordinates 
 * 
 * @param   _screen_position    Cords on the screen
 * @return                      Possition on the grid
*/
inline ivec2 screenToGridPosition(ivec2 _screen_position);

#endif
