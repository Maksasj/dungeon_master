#define EXTREME_MODE

#include "../include/main.h"

int main() {
    *_DISPLAY_CONTROL_ = _DISPLAY_CONTROL_MODE_0_ | _DISPLAY_CONTROL_BG_0_ | _SPRITE_ENABLE_ | _SPRITE_MAP_1D_;

    counterInit();
    counterStart();

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
            case 0: {
                spritePosition(selectionArrow, 130, 59);
                spriteSetOffset(buttonPlay, 0); 
                spriteSetOffset(buttonAbout, 960); 
                break;
            }
            case 1: {
                spritePosition(selectionArrow, 130, 100);
                spriteSetOffset(buttonPlay, 896);
                spriteSetOffset(buttonAbout, 64);
                break;
            }
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

    World world;
    world.floorCount = 3;
    generateFloor(&world);

    memcpy16DMA((u16*) _SPRITE_PALETTE_, (u16*) image_palette, _PALETTE_SIZE_);
    memcpy16DMA((u16*) _SPRITE_IMAGE_MEMORY_, (u16*) image_data, (image_width * image_height) / 2);
    spriteClear(sprites, &next_sprite_index);

    playSound(GAME_SOUNDTRACK, _GAME_SOUNDTRACK_BYTES_, 8000, 'A');

    gotoRoom(&world, 0, sprites, &next_sprite_index);

    //TODO: add choice of classes
    Entity player;
    Class chosen_class = WARRIOR;

    switch (chosen_class) {
        case WARRIOR: {
            player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 1, 0, 1, 0), 0);
            player.attack_callback = &warriorAttack;
            player.calculate_damage_callback = &warriorCalculateDamage;
            break;
        }
        case WIZARD: {
            player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 1, 1, 0, 0), 0);
            player.attack_callback = &wizardAttack;
            player.calculate_damage_callback = &wizardCalculateDamage;
            break;
        }
        case ARCHER: {
            player = entityInit(newFVec2(_SCREEN_WIDTH_ / 2 - 8, _SCREEN_HEIGHT_ / 2 - 8), stats(3, 2, 0, 0, 0), 0);
            player.attack_callback = &archerAttack;
            player.calculate_damage_callback = &archerCalculateDamage;
            break;
        }
        default:
            break;
    }

    entityInitSprite(&player, sprites, &next_sprite_index);
    player.update_callback = &playerUpdate;
    player.die_callback = &killPlayer;
    player.dodge_callback = &playerTryDodge;

    PlayerUI playerUI;
    initPlayerUI(&playerUI, sprites, &next_sprite_index);

    player.spec = malloc(sizeof(PlayerSpecData));
    initPlayerSpec(sprites, &next_sprite_index, &player, player.spec, &playerUI, chosen_class);

    //Text text;
    //loadTextGlyphs(sprites, &next_sprite_index, &text, "Privet soskar !");

    Entity projectile = projectileInit(newFVec2(_SCREEN_WIDTH_ / 4 - 8, _SCREEN_HEIGHT_ / 4 - 8), 0);
    projectile.update_callback = &projectileUpdate;
    projectile.die_callback = &destroyProjectile;
    entityInitSprite(&projectile, sprites, &next_sprite_index);
    projectile.facing = RIGHT;
    tryPushProjectileToRoom(&world.rooms[world.activeRoom], projectile);
    
    Timer timer;
    initTimer(&timer);
    startTimer(&timer);

    while (1) {
        updateWorld(&world, &player);
        entityUpdate(&player);

        ivec3 time = formatTime(&timer);
        //log(LOG_INFO, "%d", *_TIMER_3_DATA_);
        //log(LOG_INFO, "%d:%d:%d", time.x, time.y, time.z);
        
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
