#include "../../include/text/text.h"

int str_length(const char* source) {
    int count; 
    for (count = 0; source[count] != '\0'; ++count);
    return count; 
}

void loadTextGlyphs(Sprite* _sprites, i32* _next_sprite_index, Text* text, const char* source) {
    text->glyphs = malloc(str_length(source) * sizeof(Sprite*));

    int i;
    for(i = 0; source[i] != '\0'; ++i) {
        i8 character = source[i];
        text->number_of_glyphs++;
        text->glyphs[i] = spriteInit(_sprites, _next_sprite_index, 32 + (7)*i, 32, SIZE_8_8, 0, 0, 0, 1);
        spriteSetOffset(text->glyphs[i], 766 + (character)*2); //832 - !
    }
}

void unloadTextGlyphs(Text* text) {
    int i;
    for(i = 0; i < text->number_of_glyphs; ++i) {
        spritePosition(text->glyphs[i], -64, -64);
        text->glyphs[i] = NULL;
    }
}
