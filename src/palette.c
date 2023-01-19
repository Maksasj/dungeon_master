#include "../include/palette.h"

void setPalette(u16* _target, u16* _palette) {
    _target[1] = _palette[1];
    _target[2] = _palette[5];
    _target[5] = _palette[2];
    _target[6] = _palette[3];
    _target[7] = _palette[6];
    _target[8] = _palette[4];
    _target[33] = _palette[2];
}

u16* getRandomPalette(u16** _palettes) {
    u8 randomIndex = random() % 8;
    return _palettes[randomIndex]; 
}

void fillPalette(u16* _target, u16 _color) {
    i32 o;
    for(o = 0; o < 256; ++o) {
        _target[o] = _color;
    }
}