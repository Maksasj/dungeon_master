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

    u16 MAP[1024];
    
    i8 down_pressed = 0;
    i8 up_pressed = 0;
    i32 selection = 0;

    interruptionInit(onVBlank);
    soundInit(5, 3, 0, 3);

    i32 i; i32 j;

    _INIT_MAIN_MENU_SPRITES_
    _INIT_MAIN_MENU_BACKGROUND_
    
    memcpy16DMA((u16*) screenBlock(13), (u16*) MAP, 32 * 32);

    u32 _seed = 0;
    while(1) {
        ++_seed;

        if(buttonPressed(_BUTTON_DOWN_) && down_pressed == 0) {
            selection = selection == 0 ? MAIN_MENU_OPTION_COUNT - 1 : selection - 1;
            down_pressed = 1;
            notePlay(NOTE_B, 0);
        }

        if(buttonPressed(_BUTTON_UP_) && up_pressed == 0) {
            selection = selection == MAIN_MENU_OPTION_COUNT - 1 ? 0 : selection + 1;
            up_pressed = 1;
            notePlay(NOTE_B, 0);
        }

        if(!buttonPressed(_BUTTON_DOWN_))
            down_pressed = 0;

        if(!buttonPressed(_BUTTON_UP_))
            up_pressed = 0;

        switch (selection) {
            case 0:
                spritePosition(selectionArrow, 130, 59);
                spriteSetOffset(buttonPlay, 0); 
                spriteSetOffset(buttonAbout, 960); 
                break;
            case 1:
                spritePosition(selectionArrow, 130, 100);
                spriteSetOffset(buttonPlay, 896);
                spriteSetOffset(buttonAbout, 64);
                break;
        }

        if(buttonPressed(_BUTTON_SELECT_)) {
            if(selection == 0) {
                break;
            } else if(selection == 1) {
                notePlay(NOTE_GIS, 0);
            }
        }

        spriteUpdateAll(sprites);
    }

    int ppp;
    for(ppp = 0; ppp < _seed % 256; ++ppp) {
        random(ppp);
    }

    World world;
        generateWorld(&world, _seed);

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2);
    spriteClear(sprites, &next_sprite_index);

    playSound(GAME_SOUNDTRACK, _GAME_SOUNDTRACK_BYTES_, 8000, 'A');

    gotoRoom(&world, 0, sprites, &next_sprite_index);

    Entity player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 2, 0, 0, 0), 0);
        entityInitSprite(&player, sprites, &next_sprite_index);
        player.update_callback = &player_update;
        player.attack_callback = &playerCalculateDamage;
        player.die_callback = &killPlayer;
        player.dodge_callback = &playerTryDodge;

        PlayerUI playerUI;
        initPlayerUI(&playerUI, sprites, &next_sprite_index);

        player.spec = malloc(sizeof(PlayerSpecData));
        initPlayerSpec(sprites, &next_sprite_index, &player, player.spec, &playerUI);

    //Text text;
    //loadTextGlyphs(sprites, &next_sprite_index, &text, "Privet soskar !");

    while (1) {
        updateWorld(&world, &player);
        entityUpdate(&player);
        
        updatePlayerSpec(player.spec, &player);
        (player.update_callback)(&player, &world, &world.rooms[world.activeRoom]);

        spriteUpdateAll(sprites);

        #ifndef EXTREME_MODE
            waitVBlank();
        #else
            delay(200);
        #endif
    }
}
