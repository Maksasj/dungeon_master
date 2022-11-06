#include "include/player.h"
#include "include/defines.h"

void player_init(
    struct Sprite sprites[],
    int* next_sprite_index,
    struct Player* player
    ) {
    player->x = SCREEN_WIDTH / 2 - 16;
    player->y = SCREEN_HEIGHT / 2 - 16;

    player->frame = 0;
    player->move = 0;
    
    player->counter = 0;
    //koopa->animation_delay = 8;
    player->sprite = sprite_init(sprites, next_sprite_index, player->x, player->y, SIZE_32_32, 0, 0, player->frame, 0);
}

void player_stop(struct Player* player) {
    player->move = 0;
    player->frame = 0;
    player->counter = 7;
    sprite_set_offset(player->sprite, player->frame);
}

/* update the koopa */
void player_update(struct Player* player) {
    sprite_position(player->sprite, player->x, player->y);
}
