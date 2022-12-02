#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sprite.h"
#include "types.h"
#include "entity/entity.h"

typedef struct PlayerSpecData {
    Sprite* armor;
    Sprite* weapon;
} PlayerSpecData;

void initPlayerSpec(Sprite _sprites[], i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec);

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity);

#endif
