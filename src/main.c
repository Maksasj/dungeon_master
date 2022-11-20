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
    gotoRoom(&world, 0, sprites, &next_sprite_index);
    
    interruptionInit(onVBlank);

    i32 octave = 0;
    soundInit(5, 3, 0, 3);
    
    //play test sound
    //playSound(TEST, _TEST_BYTES_, 16000, 'B');
    
    spriteClear(sprites, &next_sprite_index);

    Entity player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8));
    entityInitSprite(&player, sprites, &next_sprite_index);
        
    //Entity enemy;
    //entityInit(sprites, &next_sprite_index, &enemy, newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8));

    while (1) {
        //Slow down the player
        player.vel.x *= 0.6;
        player.vel.y *= 0.6;

        entityUpdate(&player);

        i32 walk = 0;
        if (buttonPressed(_BUTTON_RIGHT_)) {
            player.vel.x += 0.5;

            spriteSetOffset(player.sprite, 16);
            spriteSetHorizontalFlip(player.sprite, 0);

            //notePlay(NOTE_BES, octave + 1);
        }

        if (buttonPressed(_BUTTON_LEFT_)) {
            player.vel.x -= 0.5;

            spriteSetOffset(player.sprite, 16);
            spriteSetHorizontalFlip(player.sprite, 1);

            //notePlay(NOTE_B, octave);
        }

        if (buttonPressed(_BUTTON_DOWN_)) {
            player.vel.y += 0.5;
            spriteSetOffset(player.sprite, 8);

            //notePlay(NOTE_F, octave);
        }

        if (buttonPressed(_BUTTON_UP_)) {
            player.vel.y -= 0.5;
            spriteSetOffset(player.sprite, 0);

            //notePlay(NOTE_A, octave);
        }

        //X
        if(worldCollision(&world, newIVec2(player.position.x + player.vel.x, player.position.y)) != WALL)
            player.position.x += player.vel.x;

        //Y
        if(worldCollision(&world, newIVec2(player.position.x, player.position.y + player.vel.y)) != WALL)
            player.position.y += player.vel.y;

        if(worldCollision(&world, newIVec2(player.position.x, player.position.y)) == OPENED_DOOR) {
            player.position.x = _SCREEN_WIDTH_ / 2 - 8;
            player.position.y = _SCREEN_HEIGHT_ - 24;

            ++world.activeRoom;
            gotoRoom(&world, world.activeRoom, sprites, &next_sprite_index);

        }

        waitVBlank();
        spriteUpdateAll(sprites);

        delay(100);
    }
}
