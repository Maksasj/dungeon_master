#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "buttons.h"
#include "sprite.h"
#include "types.h"
#include "entity/entity.h"
#include "world.h"

typedef struct PlayerSpecData {
    Sprite* armor;
    Sprite* weapon;

    Sprite* sprites;
    i32* next_sprite_index;
} PlayerSpecData;

typedef struct PlayerUI {
    Sprite* health[3];
    Sprite* manaBar;
} PlayerUI;

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index);

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec);

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity);

void player_update(Entity* _self, World* _world, Room* _room);

#endif
