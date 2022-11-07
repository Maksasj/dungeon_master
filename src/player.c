#include "include/player.h"

void playerInit(Sprite _sprites[], i32* _next_sprite_index, Player* _player) {
    _player->x = SCREEN_WIDTH / 2 - 16;
    _player->y = SCREEN_HEIGHT / 2 - 16;

    _player->frame = 0;
    _player->move = 0;
    
    _player->counter = 0;
    _player->sprite = spriteInit(_sprites, _next_sprite_index, _player->x, _player->y, SIZE_32_32, 0, 0, _player->frame, 0);
}

void playerStop(Player* _player) {
    _player->move = 0;
    _player->frame = 0;
    _player->counter = 7;
    spriteSetOffset(_player->sprite, _player->frame);
}

/* update the koopa */
void playerUpdate(Player* _player) {
    spritePosition(_player->sprite, _player->x, _player->y);
}
