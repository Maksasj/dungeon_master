#include "../../include/text/text.h"

int str_length(const char* source) {
    int count; 
    for (count = 0; source[count] != '\0'; ++count);
    return count; 
}

void loadTextGlyphs(Sprite* _sprites, i32* _next_sprite_index, Text* text, char* source, ivec2 pos) {
    text->glyphs = malloc(str_length(source) * sizeof(Sprite*));
    text->number_of_glyphs = 0;

    int i;
    for(i = 0; source[i] != '\0'; ++i) {
        i8 character = source[i];
        text->number_of_glyphs++;

        text->glyphs[i] = spriteInit(
            _sprites, 
            _next_sprite_index, 
            pos.x + (7)*i, 
            pos.y, 
            SIZE_8_8, 
            0, 0, 0, 2);
        
        spriteSetOffset(text->glyphs[i], 766 + (character)*2); //832 - !
    }
}

void setTextPossition(Text* text, ivec2 pos) {
    int i;
    for(i = 0; i < text->number_of_glyphs; ++i) {
        spritePosition(text->glyphs[i], pos.x + (7)*i, pos.y);
    }
}

void updateTextGlyphs(Text* text, char* source, ivec2 pos) {
    int i;
    for(i = 0; i < text->number_of_glyphs; ++i) {
        i8 character = source[i];
        spritePosition(text->glyphs[i], pos.x + (7)*i, pos.y);
        spriteSetOffset(text->glyphs[i], 766 + (character)*2); //832 - !
    }
}

void setCharacterTextGlyph(Text* text, i32 index, char character) {
    spriteSetOffset(text->glyphs[index], 766 + (character)*2);
}

void unloadTextGlyphs(Text* text) {
    int i;
    for(i = 0; i < text->number_of_glyphs; ++i) {
        spritePosition(text->glyphs[i], -64, -64);
        text->glyphs[i] = NULL;
    }
    
    text->number_of_glyphs = 0;
}
