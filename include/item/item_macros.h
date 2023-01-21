#ifndef _ITEM_MACROS_H_
#define _ITEM_MACROS_H_

#include "item.h"

#include "prototypes/wooden_bow.h"
#include "prototypes/golden_bow.h"
#include "prototypes/aqua_bow.h"

#include "prototypes/short_sword.h"
#include "prototypes/dark_claymore.h"
#include "prototypes/ice_sword.h"

#include "prototypes/gem_staff.h"
#include "prototypes/ice_staff.h"
#include "prototypes/fire_staff.h"

/*
    592 - cobalt arrow horizontal | 736 - cobalt arrow vetical
    584 - golden arrow horizontal | 728 - golden arrow vetical
    576 - iron arrow   horizontal | 720 - iron arrow   vetical

    568 - fireball horizontal     | 712 - fireball vetical
    560 - iceball  horizontal     | 704 - iceball  vetical
    552 - gemball  horizontal     | 696 - gemball  vetical
*/

/* Macros for all items in the game */
/* Bows */
#define _WOODEN_BOW_ITEM_                                               \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 480,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &woodenBowUseCallback                      \
    })                                                                  \

#define _GOLDEN_BOW_ITEM_                                               \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 504,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &goldenBowUseCallback                      \
    })                                                                  \

#define _AQUA_BOW_ITEM_                                                 \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 528,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &aquaBowUseCallback                        \
    })                                                                  \

/* Swords */
#define _SHORT_SWORD_ITEM_                                              \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 184,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &shortSwordUseCallback                     \
    })                                                                  \

#define _DARK_CLAYMORE_ITEM_                                            \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 208,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &darkClaymoreUseCallback                   \
    })                                                                  \

#define _ICE_SWORD_ITEM_                                                \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 232,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &iceSwordUseCallback                       \
    })                                                                  \

/* Staff */
#define _GEM_STAFF_ITEM_                                                \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 408,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &gemStaffUseCallback                       \
    })                                                                  \

#define _ICE_STAFF_ITEM_                                                \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 432,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &iceStaffUseCallback                       \
    })                                                                  \

#define _FIRE_STAFF_ITEM_                                               \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 456,                                           \
        .type = WEAPON,                                                 \
                                                                        \
        .use_item_callback = &fireStaffUseCallback                      \
    })                                                                  \

/* Warrior armors */
#define _IRON_CHESTPLATE_ITEM_                                          \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 112,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

#define _GOLDEN_CHESTPLATE_ITEM_                                        \
    itemReload((Item){                                                  \
        .base_stats = stats(1, 0, 0, 0, 2),                             \
        .sprite_offset = 136,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

#define _DIAMOND_CHESTPLATE_ITEM_                                       \
    itemReload((Item){                                                  \
        .base_stats = stats(2, 0, 0, 0, 3),                             \
        .sprite_offset = 160,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

/* Mage armors */
#define _PURPLE_MAGE_ARMOR_ITEM_                                        \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 336,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

#define _RED_MAGE_ARMOR_ITEM_                                           \
    itemReload((Item){                                                  \
        .base_stats = stats(1, 0, 0, 0, 2),                             \
        .sprite_offset = 360,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

#define _ENCHANTER_MAGE_ARMOR_ITEM_                                     \
    itemReload((Item){                                                  \
        .base_stats = stats(2, 0, 0, 0, 3),                             \
        .sprite_offset = 384,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

/* Archer armors */
#define _ARCHER_IRON_ARMOR_ITEM_                                        \
    itemReload((Item){                                                  \
        .base_stats = stats(0, 0, 0, 0, 1),                             \
        .sprite_offset = 768,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

#define _ARCHER_GOLDEN_ARMOR_ITEM_                                      \
    itemReload((Item){                                                  \
        .base_stats = stats(1, 0, 0, 0, 2),                             \
        .sprite_offset = 768,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

#define _ARCHER_DIAMOND_ARMOR_ITEM_                                     \
    itemReload((Item){                                                  \
        .base_stats = stats(2, 0, 0, 0, 3),                             \
        .sprite_offset = 768,                                           \
        .type = ARMOR                                                   \
    })                                                                  \

/* Macros for all item drops in the game */
#define _IRON_CHESTPLATE_ITEM_DROP_(X, Y)               itemDropInit(newIVec2(X, Y), _IRON_CHESTPLATE_ITEM_,        280)
#define _GOLDEN_CHESTPLATE_ITEM_DROP_(X, Y)             itemDropInit(newIVec2(X, Y), _GOLDEN_CHESTPLATE_ITEM_,      288)
#define _DIAMOND_CHESTPLATE_ITEM_DROP_(X, Y)            itemDropInit(newIVec2(X, Y), _DIAMOND_CHESTPLATE_ITEM_,     296)

#define _SHORT_SWORD_ITEM_DROP_(X, Y)                   itemDropInit(newIVec2(X, Y), _SHORT_SWORD_ITEM_,            256)
#define _DARK_CLAYMORE_ITEM_DROP_(X, Y)                 itemDropInit(newIVec2(X, Y), _DARK_CLAYMORE_ITEM_,          264)
#define _ICE_SWORD_ITEM_DROP_(X, Y)                     itemDropInit(newIVec2(X, Y), _ICE_SWORD_ITEM_,              272)

#define _PURPLE_MAGE_ARMOR_ITEM_DROP_(X, Y)             itemDropInit(newIVec2(X, Y), _PURPLE_MAGE_ARMOR_ITEM_,      648)
#define _RED_MAGE_ARMOR_ITEM_DROP_(X, Y)                itemDropInit(newIVec2(X, Y), _RED_MAGE_ARMOR_ITEM_,         656)
#define _ENCHANTER_MAGE_ARMOR_ITEM_DROP_(X, Y)          itemDropInit(newIVec2(X, Y), _ENCHANTER_MAGE_ARMOR_ITEM_,   664)

#define _ARCHER_IRON_ARMOR_ITEM_DROP_(X, Y)             itemDropInit(newIVec2(X, Y), _ARCHER_IRON_ARMOR_ITEM_,      672)
#define _ARCHER_GOLDEN_ARMOR_ITEM_DROP_(X, Y)           itemDropInit(newIVec2(X, Y), _ARCHER_GOLDEN_ARMOR_ITEM_,    680)
#define _ARCHER_DIAMOND_ARMOR_ITEM_DROP_(X, Y)          itemDropInit(newIVec2(X, Y), _ARCHER_DIAMOND_ARMOR_ITEM_,   688)

#define _GEM_STAFF_ITEM_DROP_(X, Y)                     itemDropInit(newIVec2(X, Y), _GEM_STAFF_ITEM_,              600)
#define _ICE_STAFF_ITEM_DROP_(X, Y)                     itemDropInit(newIVec2(X, Y), _ICE_STAFF_ITEM_,              608)
#define _FIRE_STAFF_ITEM_DROP_(X, Y)                    itemDropInit(newIVec2(X, Y), _FIRE_STAFF_ITEM_,             616)

#define _WOODEN_BOW_ITEM_DROP_(X, Y)                    itemDropInit(newIVec2(X, Y), _WOODEN_BOW_ITEM_,             624)
#define _GOLDEN_BOW_ITEM_DROP_(X, Y)                    itemDropInit(newIVec2(X, Y), _GOLDEN_BOW_ITEM_,             632)
#define _AQUA_BOW_ITEM_DROP_(X, Y)                      itemDropInit(newIVec2(X, Y), _AQUA_BOW_ITEM_,               640)

#endif
