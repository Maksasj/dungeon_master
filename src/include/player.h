#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sprite.h"
#include "types.h"

typedef struct Player {
    Sprite* sprite;

    float x, y;

    i32 frame;

    i32 animation_delay;

    fvec2 vel;

    i32 counter;

    i32 move;
} Player;

void playerInit(Sprite _sprites[], i32* _next_sprite_index, Player* _player);

void playerStop(Player* _player);

void playerUpdate(Player* _player);

#endif
