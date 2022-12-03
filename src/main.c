#include "include/types.h"
#include "include/text/text.h"

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

#include "../assets/generated/music/game_soundtrack_long.h"

#include "include/background.h"

#include "../assets/generated/sprites.h"

#include "include/logger.h"

#define EXTREME_MODE

int main() {
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

    soundInit(5, 3, 0, 3);
    playSound(GAME_SOUNDTRACK, _GAME_SOUNDTRACK_BYTES_, 8000, 'A');
    
    spriteClear(sprites, &next_sprite_index);

    Entity player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(1, 1, 1, 1, 1), 0);
        entityInitSprite(&player, sprites, &next_sprite_index);
        player.update_callback = &player_update;
        
        player.spec = malloc(sizeof(PlayerSpecData));
        initPlayerSpec(sprites, &next_sprite_index, &player, player.spec);

    PlayerUI playerUI;
    initPlayerUI(&playerUI, sprites, &next_sprite_index);

    Text text;
    loadTextGlyphs(sprites, &next_sprite_index, &text, "Privet soskar !");

    while (1) {
        updateWorld(&world, &player);
        entityUpdate(&player);
            (player.update_callback)(&player, &world, &world.rooms[world.activeRoom]);
        spriteUpdateAll(sprites);

        #ifndef EXTREME_MODE
            waitVBlank();
        #else
            delay(300);
        #endif
    }
}
