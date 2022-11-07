#include "include/defines.h"
#include "include/delay.h"
#include "include/player.h"
#include "include/sprite.h"
#include "include/memory.h"

#include "../assets/generated/pog.h"

int main() {
    struct Sprite sprites[NUM_SPRITES];
    int next_sprite_index = 0;

    /* we set the mode to mode 0 with bg0 on */
    *display_control = MODE0 | BG0_ENABLE | SPRITE_ENABLE | SPRITE_MAP_1D;

    /* setup the background 0 */

    memcpy16_dma((unsigned short*) sprite_palette, (unsigned short*) image_palette, PALETTE_SIZE); /* load the palette from the image into palette memory*/
    
    memcpy16_dma((unsigned short*) sprite_image_memory, (unsigned short*) image_data, (image_width * image_height) / 2); /* load the image into sprite image memory */

    setup_background();
    /* clear all the sprites on screen now */
    sprite_clear(sprites, &next_sprite_index);

    /* create the koopa */
    struct Player player;
    player_init(sprites, &next_sprite_index, &player);
    
    /* set initial scroll to 0 */
    int xscroll = 0;
    int yscroll = 0;

    /* loop forever */
    while (1) {
        /* update the koopa */
        player_update(&player);

        /* now the arrow keys move the koopa */
        int walk = 0;
        if (button_pressed(BUTTON_RIGHT)) {
            xscroll++;
            walk = 1;
            sprite_set_horizontal_flip(player.sprite, 0);

            sprite_set_offset(player.sprite, 64);

            player.move = 1;
        }

        if (button_pressed(BUTTON_LEFT)) {
            xscroll--;
            walk = 1;

            sprite_set_offset(player.sprite, 96);

            player.move = 1;
        }

        if (button_pressed(BUTTON_DOWN)) {
            yscroll++;
            walk = 1;

            sprite_set_offset(player.sprite, 0);

            player.move = 1;
        }

        if (button_pressed(BUTTON_UP)) {
            yscroll--;
            walk = 1;
            
            sprite_set_offset(player.sprite, 32);

            player.move = 1;
        }

        /* wait for vblank before scrolling and moving sprites */
        wait_vblank();
        *bg0_x_scroll = xscroll;
        *bg0_y_scroll = yscroll;
        sprite_update_all(sprites);

        delay(100);
    }
}
