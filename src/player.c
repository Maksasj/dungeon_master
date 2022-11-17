#include "include/player.h"

void playerInit(Sprite _sprites[], i32* _next_sprite_index, Player* _player) {
    _player->x = _SCREEN_WIDTH_ / 2 - 8;
    _player->y = _SCREEN_HEIGHT_ / 2 - 8;

    _player->frame = 0;
    _player->move = 0;
    
    _player->vel = newFVec2(0, 0);

    _player->counter = 0;
    _player->sprite = spriteInit(_sprites, _next_sprite_index, _player->x, _player->y, SIZE_16_16, 0, 0, _player->frame, 0);
}

void playerStop(Player* _player) {
    _player->move = 0;
    _player->frame = 0;
    _player->counter = 7;
    spriteSetOffset(_player->sprite, _player->frame);
}

void playerUpdate(Player* _player) {
    spritePosition(_player->sprite, (int) _player->x, (int) _player->y);
}
