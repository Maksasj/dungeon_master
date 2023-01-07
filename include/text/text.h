/**
 * delay
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows to render text using sprite system
*/

#ifndef _TEXT_H_
#define _TEXT_H_

#include <stdlib.h>

#include "../utils/logger.h"

#include "../utils/types.h"
#include "../sprite.h"

/* Main structure that contains all text glyphs */
typedef struct Text {
    /* Array of glyphs for each letter */
    Sprite** glyphs;
    /* Total amount of glyphs in presented text */
    u32 number_of_glyphs;
} Text;

/**
 * Loades text glyphs into sprite memory
 * 
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index   
 * @param   _text Pointer to text structure it self   
 * @param   _source   Text string
 * @param   _pos   Possition where to place loaded text
*/
void loadTextGlyphs(Sprite* _sprites, i32* _next_sprite_index, Text* _text, char* _source, ivec2 _pos);

/**
 * Updates text field
 * 
 * @param   _text  Pointer to text structure it self
 * @param   _source String that will be used to update already existing one 
 * @param   _pos New position for text
*/
void updateTextGlyphs(Text* _text, char* _source, ivec2 _pos);

/**
 * Updates text position
 * 
 * @param   _text  Pointer to text structure it self
 * @param   _pos New position for text
*/
void setTextPosition(Text* _text, ivec2 _pos);

/**
 * Updates text glyphs
 * 
 * @param   _text  Pointer to text structure it self
*/
void unloadTextGlyphs(Text* _text);

/**
 * Used to get length of given string
 * 
 * @param   _source  String
 * @return length of the string
*/
int str_length(const char* _source);

#endif
