#include "include/types.h"
#include "include/memory.h"
#include "include/gfx.h"
#include "include/world.h"
#include "include/sprite.h"
#include "include/buttons.h"
#include "include/delay.h"
#include "include/player.h"
#include "include/interruption.h"
#include "include/sound.h"

#include "include/entity/entity.h"

#include "assets/test_sound.h"
#include "include/background.h"

#include "../assets/generated/player1.h"


int main() {
    /* we set the mode to mode 0 with bg0 on */
    *_DISPLAY_CONTROL_ = _DISPLAY_CONTROL_MODE_0_ | _DISPLAY_CONTROL_BG_0_ | _SPRITE_ENABLE_ | _SPRITE_MAP_1D_;

    initBackground();

    Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_); /* load the palette from the image into palette memory*/
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2); /* load the image into sprite image memory */

    World world;
    generateWorld(&world);
    gotoRoom(&world, 0);
    
    interruptionInit(onVBlank);

    i32 octave = 0;
    soundInit(5, 3, 0, 3);
    
    //play test sound
    playSound(TEST, _TEST_BYTES_, 16000, 'B');
    
    spriteClear(sprites, &next_sprite_index);

    // Player player;
    // playerInit(sprites, &next_sprite_index, &player);

    Entity entity;
    entityInit(sprites, &next_sprite_index, &entity);
        
    while (1) {
        //Slow down the player
        // player.vel.x *= 0.6;
        // player.vel.y *= 0.6;

        // playerUpdate(&player);

        entity.vel.x *= 0.6;
        entity.vel.y *= 0.6;

        entityUpdate(&entity);

        i32 walk = 0;
        if (buttonPressed(_BUTTON_RIGHT_)) {
            //player.vel.x += 0.5;
            entity.vel.x += 0.5;

            // spriteSetOffset(player.sprite, 16);
            // spriteSetHorizontalFlip(player.sprite, 0);

            spriteSetOffset(entity.sprite, 16);
            spriteSetHorizontalFlip(entity.sprite, 0);

            notePlay(NOTE_BES, octave + 1);
        }

        if (buttonPressed(_BUTTON_LEFT_)) {
            // player.vel.x -= 0.5;

            // spriteSetOffset(player.sprite, 16);
            // spriteSetHorizontalFlip(player.sprite, 1);

            entity.vel.x -= 0.5;

            spriteSetOffset(entity.sprite, 16);
            spriteSetHorizontalFlip(entity.sprite, 1);

            notePlay(NOTE_B, octave);
        }

        if (buttonPressed(_BUTTON_DOWN_)) {
            // player.vel.y += 0.5;
            // spriteSetOffset(player.sprite, 8);

            entity.vel.y += 0.5;
            spriteSetOffset(entity.sprite, 8);

            notePlay(NOTE_F, octave);
        }

        if (buttonPressed(_BUTTON_UP_)) {
            // player.vel.y -= 0.5;
            // spriteSetOffset(player.sprite, 0);

            entity.vel.y -= 0.5;
            spriteSetOffset(entity.sprite, 0);

            notePlay(NOTE_A, octave);
        }

        //X
        if(worldCollision(&world, newIVec2(entity.position.x + entity.vel.x, entity.position.y)) != WALL)
            entity.position.x += entity.vel.x;

        //Y
        if(worldCollision(&world, newIVec2(entity.position.x, entity.position.y + entity.vel.y)) != WALL)
            entity.position.y += entity.vel.y;

        if(worldCollision(&world, newIVec2(entity.position.x, entity.position.y)) == OPENED_DOOR) {
            entity.position.x = _SCREEN_WIDTH_ / 2 - 8;
            entity.position.y = _SCREEN_HEIGHT_ / 2 - 8;

            world.activeRoom++;
            gotoRoom(&world, world.activeRoom);
        }

        waitVBlank();
        spriteUpdateAll(sprites);

        delay(100);
    }
}
