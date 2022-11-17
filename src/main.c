#include "include/types.h"
#include "include/memory.h"
#include "include/gfx.h"
#include "include/world.h"
#include "include/sprite.h"
#include "include/buttons.h"
#include "include/delay.h"
#include "include/player.h"
#include "include/background.h"

#include "../assets/generated/player1.h"


int main() {
    Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

    /* we set the mode to mode 0 with bg0 on */
    *_DISPLAY_CONTROL_ = _DISPLAY_CONTROL_MODE_0_ | _DISPLAY_CONTROL_BG_0_ | _SPRITE_ENABLE_ | _SPRITE_MAP_1D_;

    initBackground();

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_); /* load the palette from the image into palette memory*/
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2); /* load the image into sprite image memory */

    World world;
    generateWorld(&world);
    gotoRoom(&world, 0);
    
    spriteClear(sprites, &next_sprite_index);

    Player player;
    playerInit(sprites, &next_sprite_index, &player);
    
    i32 xscroll = 0;
    i32 yscroll = 0;
        
    while (1) {
        playerUpdate(&player);

        i32 walk = 0;
        if (buttonPressed(_BUTTON_RIGHT_)) {
            ++xscroll;
            spriteSetOffset(player.sprite, 16);
            spriteSetHorizontalFlip(player.sprite, 0);

            player.move = 1;
        }

        if (buttonPressed(_BUTTON_LEFT_)) {
            --xscroll;
            spriteSetOffset(player.sprite, 16);
            spriteSetHorizontalFlip(player.sprite, 1);

            player.move = 1;
        }

        if (buttonPressed(_BUTTON_DOWN_)) {
            ++yscroll;
            spriteSetOffset(player.sprite, 8);

            player.move = 1;
        }

        if (buttonPressed(_BUTTON_UP_)) {
            --yscroll;
            spriteSetOffset(player.sprite, 0);

            player.move = 1;
        }

        player.x = xscroll;
        player.y = yscroll;

        /* wait for vblank before scrolling and moving sprites */
        waitVBlank();
        spriteUpdateAll(sprites);

        delay(100);
    }
}
