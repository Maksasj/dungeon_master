#include "../../include/text/text.h"

i32 getStringLength(const i8* _source) {
    i32 count; 
    for (count = 0; _source[count] != '\0'; ++count);
    return count; 
}

void renderText(vu16* _layer, i8* _text, ivec2 _pos) {
    i32 i;
    for(i = 0; _text[i] != '\0'; ++i) {
        _layer[_pos.x + _pos.y * 32 + i] = 256 + (_text[i] - 32);
    }
}

void loadTextGlyphs(Sprite* _sprites, i32* _next_sprite_index, Text* _text, i8* _source, ivec2 _pos) {
    _text->glyphs = malloc(getStringLength(_source) * sizeof(Sprite*));
    _text->number_of_glyphs = 0;

    i32 i;
    for(i = 0; _source[i] != '\0'; ++i) {
        i8 character = _source[i];
        ++_text->number_of_glyphs;

        _text->glyphs[i] = spriteInit(
            _sprites, 
            _next_sprite_index, 
            _pos.x + (7) * i, 
            _pos.y, 
            SIZE_8_8, 
            0, 0, 0, 2);
        
        spriteSetOffset(_text->glyphs[i], 766 + (character) * 2); //832 - !
    }
}

void setTextPosition(Text* _text, ivec2 _pos) {
    i32 i;
    for(i = 0; i < _text->number_of_glyphs; ++i) {
        spritePosition(_text->glyphs[i], _pos.x + (7) * i, _pos.y);
    }
}

void updateTextGlyphs(Text* _text, i8* _source, ivec2 _pos) {
    i32 i;
    for(i = 0; i < _text->number_of_glyphs; ++i) {
        i8 character = _source[i];
        spritePosition(_text->glyphs[i], _pos.x + (7) * i, _pos.y);
        spriteSetOffset(_text->glyphs[i], 766 + (character) * 2); //832 - !
    }
}

void setCharacterTextGlyph(Text* _text, i32 _index, i8 _character) {
    spriteSetOffset(_text->glyphs[_index], 766 + (_character) * 2);
}

void unloadTextGlyphs(Text* _text) {
    i32 i;
    for(i = 0; i < _text->number_of_glyphs; ++i) {
        spritePosition(_text->glyphs[i], -64, -64);
        _text->glyphs[i] = NULL;
    }
    
    _text->number_of_glyphs = 0;
}
