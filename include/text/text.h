#ifndef _TEXT_H_
#define _TEXT_H_

#include <stdlib.h>

#include "../utils/logger.h"

#include "../utils/types.h"
#include "../sprite.h"

typedef struct Text {
    Sprite** glyphs;
    u32 number_of_glyphs;
} Text;

void loadTextGlyphs(Sprite* _sprites, i32* _next_sprite_index, Text* text, const char* source);
void unloadTextGlyphs(Text* text);
int str_length(const char* source);

#endif
