/**
 * player
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * player entity
*/

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../buttons.h"
#include "../../sprite.h"
#include "../../utils/types.h"
#include "../entity.h"
#include "../../world/world.h"

// Enum for storing existing classes
typedef enum Class {
    WARRIOR,
    WIZARD,
    ARCHER
} Class;

// Structure for displaying data
typedef struct PlayerUI {
    Sprite* health[HEALTH_CAP];
    Sprite* manaBar;
} PlayerUI;

// Structure for storing player specs
typedef struct PlayerSpecData {
    // Player's class
    Class class;

    // Armor visual
    Sprite* armor;
    // Weapon visual
    Sprite* weapon;
    
    // Game textures
    Sprite* sprites;
    // Sprite index in game textures
    i32* next_sprite_index;

    // weapon
    Item hand_slot;
    // armor
    Item armor_slot;

    // UI
    PlayerUI* ui;
} PlayerSpecData;

/**
 * Initialize UI
 * 
 * @param _playerUI             UI
 * @param _sprites              Textures
 * @param _next_sprite_index    next sprite index
*/
void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index);

/**
 * Initialize PlayerSpec
 * 
 * @param _sprites              Textures
 * @param _next_sprite_index    next sprite index
 * @param _entity               Existing player
 * @param _pspec                Allocated player specs
 * @param _ui                   UI
 * @param chosenClass           class
*/
void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec, PlayerUI* _ui, Class chosenClass);

/**
 * Updates PlayerSpec
 * 
 * @param _entity               Existing player
 * @param _pspec                Existing player specs
*/
void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity);

/**
 * Calculates with pseudo-number generator dodge chance
 * 
 * @param _self      existing player
 * 
 * @return 0 - receives damage (false), 1 - dodged (true)
*/
i32 playerTryDodge(Entity* _self);

/**
 * Kills player
 * 
 * @param _self         existing player
*/
void killPlayer(Entity* _self);

/**
 * Updates player in worldUpdate
 * 
 * @param _self         existing player
 * @param _world        existing world
 * @param _room         existing room
*/
void player_update(Entity* _self, World* _world, Room* _room);

#endif
