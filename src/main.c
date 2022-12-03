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

#include "../assets/generated/menu.h"
#include "../assets/generated/sprites.h"

#include "include/logger.h"

#define EXTREME_MODE

int main() {
    *_DISPLAY_CONTROL_ = _DISPLAY_CONTROL_MODE_0_ | _DISPLAY_CONTROL_BG_0_ | _SPRITE_ENABLE_ | _SPRITE_MAP_1D_;

    Sprite sprites[_NUM_SPRITES_];
    i32 next_sprite_index = 0;

    initBackground();

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) menu_image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) menu_image_data, (menu_image_width * menu_image_height) / 2);
    spriteClear(sprites, &next_sprite_index);

    World world;
        generateWorld(&world);

    i32 i; i32 j;

    for(i = 0; i < 15; ++i) {
        for(j = 0; j < 10; ++j) {
            //placeTile(_world, _world->MAP, newIVec2(i*2, j*2), getRandomFloorTile(), NONE);

            world.MAP[i*2 + j*2 * 32] = 0x0015;
            world.MAP[i*2 + j*2 * 32 + 1] = 0x0016;
            world.MAP[i*2 + j*2 * 32 + 32] = 0x0035;
            world.MAP[i*2 + j*2 * 32 + 33] = 0x0036;
        }
    }

    memcpy16DMA((u16*) screenBlock(13), (u16*) world.MAP, 32 * 32);


    //Sprite* q5 = spriteInit(sprites, &next_sprite_index, 0, 64, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q5, 512);
    //Sprite* q6 = spriteInit(sprites, &next_sprite_index, 64, 64, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q6, 640);
    //Sprite* q7 = spriteInit(sprites, &next_sprite_index, 128, 64, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q7, 768);
    //Sprite* q8 = spriteInit(sprites, &next_sprite_index, 192, 64, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q8, 896);
    //
    //Sprite* q9 = spriteInit(sprites, &next_sprite_index, 0, 128, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q9, 0);
    //Sprite* q10 = spriteInit(sprites, &next_sprite_index, 64, 128, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q10, 128);
    //Sprite* q11 = spriteInit(sprites, &next_sprite_index, 128, 128, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q11, 256);
    //Sprite* q12 = spriteInit(sprites, &next_sprite_index, 192, 128, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q12, 384);
//
    //Sprite* q0 = spriteInit(sprites, &next_sprite_index, 0, 0, SIZE_64_64, 0, 0, 0, 0);
    //spriteSetOffset(q0, 0);

    while(!buttonPressed(_BUTTON_START_)) {
        spriteUpdateAll(sprites);
        delay(2000);
    }

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2);
    spriteClear(sprites, &next_sprite_index);

    
    gotoRoom(&world, 0, sprites, &next_sprite_index);

    interruptionInit(onVBlank);

    soundInit(5, 3, 0, 3);
    playSound(GAME_SOUNDTRACK, _GAME_SOUNDTRACK_BYTES_, 8000, 'A');

    Entity player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(1, 1, 1, 1, 1), 0);
        entityInitSprite(&player, sprites, &next_sprite_index);
        player.update_callback = &player_update;
        player.attack_callback = &playerCalculateDamage;
        player.cooldown_callback = &playerSetAttackCooldown;
        player.die_callback = &killPlayer;
        
        player.spec = malloc(sizeof(PlayerSpecData));
        initPlayerSpec(sprites, &next_sprite_index, &player, player.spec);

    PlayerUI playerUI;
    initPlayerUI(&playerUI, sprites, &next_sprite_index);

    Text text;
    loadTextGlyphs(sprites, &next_sprite_index, &text, "Privet soskar !");

    while (1) {
        updateWorld(&world, &player);
        entityUpdate(&player);
        
        updatePlayerSpec(player.spec, &player);
        (player.update_callback)(&player, &world, &world.rooms[world.activeRoom]);

        spriteUpdateAll(sprites);

        #ifndef EXTREME_MODE
            waitVBlank();
        #else
            delay(300);
        #endif
    }
}
