#include "include/defines.h"
#include "include/background.h"
#include "include/delay.h"
#include "include/player.h"
#include "include/sprite.h"
#include "include/memory.h"
#include "include/types.h"

#include "../assets/generated/pog.h"

int main() {
    struct Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

    /* we set the mode to mode 0 with bg0 on */
    *display_control = MODE0 | BG0_ENABLE | SPRITE_ENABLE | SPRITE_MAP_1D;

    /* setup the background 0 */

    memcpy16DMA((u16*) sprite_palette, (u16*) image_palette, _PALETTE_SIZE_); /* load the palette from the image into palette memory*/
    
    memcpy16DMA((u16*) sprite_image_memory, (u16*) image_data, (image_width * image_height) / 2); /* load the image into sprite image memory */

    setupBackground();
    /* clear all the sprites on screen now */
    spriteClear(sprites, &next_sprite_index);

    /* create the koopa */
    Player player;
    playerInit(sprites, &next_sprite_index, &player);
    
    /* set initial scroll to 0 */
    i32 xscroll = 0;
    i32 yscroll = 0;

    /* loop forever */
    while (1) {
        /* update the koopa */
        playerUpdate(&player);

        /* now the arrow keys move the koopa */
        i32 walk = 0;
        if (buttonPressed(BUTTON_RIGHT)) {
            xscroll++;
            walk = 1;
            spriteSetHorizontalFlip(player.sprite, 0);

            spriteSetOffset(player.sprite, 64);

            player.move = 1;
        }

        if (buttonPressed(BUTTON_LEFT)) {
            xscroll--;
            walk = 1;

            spriteSetOffset(player.sprite, 96);

            player.move = 1;
        }

        if (buttonPressed(BUTTON_DOWN)) {
            yscroll++;
            walk = 1;

            spriteSetOffset(player.sprite, 0);

            player.move = 1;
        }

        if (buttonPressed(BUTTON_UP)) {
            yscroll--;
            walk = 1;
            
            spriteSetOffset(player.sprite, 32);

            player.move = 1;
        }

        /* wait for vblank before scrolling and moving sprites */
        wait_vblank();
        *_BG0_X_SCROLL_ = xscroll;
        *_BG0_Y_SCROLL_ = yscroll;
        spriteUpdateAll(sprites);

        delay(100);
    }
}
