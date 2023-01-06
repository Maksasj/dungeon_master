#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../buttons.h"
#include "../../sprite.h"
#include "../../utils/types.h"
#include "../entity.h"
#include "../../world/world.h"

typedef enum Class {
    WARRIOR,
    WIZARD,
    ARCHER
} Class;

typedef struct PlayerUI {
    Sprite* health[HEALTH_CAP];
    Sprite* manaBar;
} PlayerUI;

typedef struct PlayerSpecData {
    Class class;

    Sprite* armor;
    Sprite* weapon;

    Sprite* sprites;
    i32* next_sprite_index;

    Item hand_slot;
    Item armor_slot;

    PlayerUI* ui;
} PlayerSpecData;

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index);

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec, PlayerUI* _ui, Class _class);

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity);

i32 playerTryDodge(Entity* _self);

void killPlayer(Entity* _self);

void playerUpdate(Entity* _self, World* _world, Room* _room);

#endif
