#include "include/types.h"
#include "include/memory.h"
#include "include/gfx.h"
#include "include/background.h"
#include "include/sprite.h"
#include "include/buttons.h"
#include "include/delay.h"
#include "include/player.h"
#include "include/sound.h"

#include "../assets/generated/pog.h"

int main() {
    Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

    /* we set the mode to mode 0 with bg0 on */
    *_DISPLAY_CONTROL_ = _DISPLAY_CONTROL_MODE_0_ | _DISPLAY_CONTROL_BG_0_ | _SPRITE_ENABLE_ | _SPRITE_MAP_1D_;

    i32 octave = 0;

    // turn sound on
    *_SOUND_CONTROL_ = _MASTER_SOUND_ENABLE_;
    // snd1 on left/right ; both full volume
    *_SOUND_DMG_CONTROL_ = _SDMG_BUILD_LR_(_SDMG_SQR1_, 7);
    // DMG ratio to 100%
    *_DIRECT_SOUND_CONTROL_ = _DIRECT_SOUND_DMG_100_;

    // no sweep
    *_SOUND_1_SWEEP_ = _SOUND_SWEEP_OFF_;

    // envelope: vol=12, decay, max step time (7) ; 50% duty
    *_SOUND_1_CONTROL_ = _SSQR_ENV_BUILD_(12, 0, 7) | _SSQR_DUTY1_2_;
    *_SOUND_1_FREQ_ = 0;

    /* setup the background 0 */

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_); /* load the palette from the image into palette memory*/
    
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2); /* load the image into sprite image memory */

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
        if (buttonPressed(_BUTTON_RIGHT_)) {
            ++xscroll;
            spriteSetHorizontalFlip(player.sprite, 0);

            spriteSetOffset(player.sprite, 64);

            player.move = 1;

            notePlay(NOTE_A, octave);
        }

        if (buttonPressed(_BUTTON_LEFT_)) {
            --xscroll;
            spriteSetOffset(player.sprite, 96);

            player.move = 1;

            notePlay(NOTE_B, octave);
        }

        if (buttonPressed(_BUTTON_DOWN_)) {
            ++yscroll;
            spriteSetOffset(player.sprite, 0);

            player.move = 1;

            notePlay(NOTE_F, octave);
        }

        if (buttonPressed(_BUTTON_UP_)) {
            --yscroll;
            spriteSetOffset(player.sprite, 32);

            player.move = 1;

            notePlay(NOTE_D, octave + 1);
        }

        /* wait for vblank before scrolling and moving sprites */
        waitVBlank();
        *_BG0_X_SCROLL_ = xscroll;
        *_BG0_Y_SCROLL_ = yscroll;
        spriteUpdateAll(sprites);

        delay(100);
    }
}
