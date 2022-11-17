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
        
    while (1) {
        player.vel.x *= 0.6;
        player.vel.y *= 0.6;

        playerUpdate(&player);

        i32 walk = 0;
        if (buttonPressed(_BUTTON_RIGHT_)) {
            player.vel.x += 0.5;

            spriteSetOffset(player.sprite, 16);
            spriteSetHorizontalFlip(player.sprite, 0);
        }

        if (buttonPressed(_BUTTON_LEFT_)) {
            player.vel.x -= 0.5;

            spriteSetOffset(player.sprite, 16);
            spriteSetHorizontalFlip(player.sprite, 1);
        }

        if (buttonPressed(_BUTTON_DOWN_)) {
            player.vel.y += 0.5;
            spriteSetOffset(player.sprite, 8);
        }

        if (buttonPressed(_BUTTON_UP_)) {
            player.vel.y -= 0.5;
            spriteSetOffset(player.sprite, 0);
        }

        if(!worldCollision(&world, newIVec2(player.x + player.vel.x, player.y + player.vel.y))) {
            player.x += player.vel.x;
            player.y += player.vel.y;
        }


        if(doorCollision(&world, newIVec2(player.x, player.y))) {
            player.x = _SCREEN_WIDTH_ / 2 - 8;
            player.y = _SCREEN_HEIGHT_ / 2 - 8;

            world.activeRoom++;
            gotoRoom(&world, world.activeRoom);
        }

        waitVBlank();
        spriteUpdateAll(sprites);

        delay(100);
    }
}
