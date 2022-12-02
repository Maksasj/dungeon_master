#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sprite.h"
#include "types.h"
#include "entity/entity.h"
#include "world/room.h"

typedef struct PlayerSpecData {
    Sprite* armor;
    Sprite* weapon;
} PlayerSpecData;

typedef struct PlayerUI {
    Sprite* health[3];
    Sprite* manaBar;
} PlayerUI;

void initPlayerUI(PlayerUI* _playerUI, Sprite* _sprites, i32* _next_sprite_index);

void initPlayerSpec(Sprite _sprites[], i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec);

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity);

void playerAttack(Entity* _self, Room* _active_room);

i32 playerCalculateDamage();

void playerSetAttackCooldown(Entity* _self);

#endif
