#include "include/types.h"
#include "include/memory.h"
#include "include/gfx.h"
#include "include/world.h"
#include "include/sprite.h"
#include "include/buttons.h"
#include "include/delay.h"
#include "include/player.h"

#include "../assets/generated/pog.h"

int main() {
    *_DISPLAY_CONTROL_ = _DISPLAY_CONTROL_MODE_0_ | _DISPLAY_CONTROL_BG_0_ | _SPRITE_ENABLE_ | _SPRITE_MAP_1D_;
    
    Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

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

    *_BG0_X_SCROLL_ = 0;
    *_BG0_Y_SCROLL_ = 8;

    while (1) {
        playerUpdate(&player);

        i32 walk = 0;
        if (buttonPressed(_BUTTON_RIGHT_)) {
            spriteSetHorizontalFlip(player.sprite, 0);

            spriteSetOffset(player.sprite, 64);

            player.move = 1;
        }

        if (buttonPressed(_BUTTON_LEFT_)) {
            spriteSetOffset(player.sprite, 96);

            player.move = 1;
        }

        if (buttonPressed(_BUTTON_DOWN_)) {
            spriteSetOffset(player.sprite, 0);

            player.move = 1;
        }

        if (buttonPressed(_BUTTON_UP_)) {
            spriteSetOffset(player.sprite, 32);

            player.move = 1;
        }

        player.x = xscroll;
        player.y = yscroll;

        waitVBlank();
        spriteUpdateAll(sprites);

        delay(100);
    }
}
