#define EXTREME_MODE

#include "include/main.h"

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

    _INIT_MAIN_MENU_SPRITES_
    _INIT_MAIN_MENU_BACKGROUND_
    
    memcpy16DMA((u16*) screenBlock(13), (u16*) world.MAP, 32 * 32);

    while(!buttonPressed(_BUTTON_START_)) {
        spriteUpdateAll(sprites);
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
