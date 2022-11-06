#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"

struct Player {
    struct Sprite* sprite;

    int x, y;

    int frame;

    int animation_delay;

    int counter;

    int move;
};

void player_init(struct Sprite sprites[], int* next_sprite_index, struct Player* player);

void player_stop(struct Player* player);

void player_update(struct Player* player);

#endif
