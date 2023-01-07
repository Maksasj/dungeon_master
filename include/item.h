#ifndef _ITEM_H_
#define _ITEM_H_

#include "entity/statblock.h"

#include "sprite.h"
#include "utils/types.h"

typedef enum ItemType {
    ARMOR,
    WEAPON
} ItemType;

typedef struct Item {
    Statblock base_stats;

    u32 sprite_offset;

    ItemType type;

    i8 count;
} Item;

typedef struct ItemDrop {
    Sprite* sprite;
    SpriteSize sprite_size_in_pixels;
    
    ivec2 position;

    u32 sprite_offset;

    Item item;
} ItemDrop;

ItemDrop itemDropInit(ivec2 _position, Item _item, u32 _sprite_offset);

void itemDropInitSprite(ItemDrop* _itemDrop, Sprite _sprites[], i32* _next_sprite_index);

void itemDropUnloadSprite(ItemDrop *_itemDrop);

Item itemInit(Statblock _stat, u32 _sprite_offset, ItemType type);

#define _IRON_CHESTPLATE_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 112, ARMOR)
#define _GOLDEN_CHESTPLATE_ITEM_ itemInit(stats(1, 0, 0, 0, 2), 136, ARMOR)
#define _DIAMOND_CHESTPLATE_ITEM_ itemInit(stats(2, 0, 0, 0, 3), 160, ARMOR)

#define _SHORT_SWORD_ITEM_ itemInit(stats(0, 0, 0, 1, 0), 184, WEAPON)
#define _DARK_CLAYMORE_ITEM_ itemInit(stats(0, 0, 0, 2, 0), 208, WEAPON)
#define _ICE_SWORD_ITEM_ itemInit(stats(0, 1, 0, 1, 0), 232, WEAPON)

#define _IRON_CHESTPLATE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _IRON_CHESTPLATE_ITEM_, 280)
#define _GOLDEN_CHESTPLATE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _GOLDEN_CHESTPLATE_ITEM_, 288)
#define _DIAMOND_CHESTPLATE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _DIAMOND_CHESTPLATE_ITEM_, 296)

#define _SHORT_SWORD_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _SHORT_SWORD_ITEM_, 256)
#define _DARK_CLAYMORE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _DARK_CLAYMORE_ITEM_, 264)
#define _ICE_SWORD_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ICE_SWORD_ITEM_, 272)

#define _PURPLE_MAGE_ARMOR_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 336, ARMOR)
#define _RED_MAGE_ARMOR_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 360, ARMOR)
#define _ENCHANTER_MAGE_ARMOR_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 384, ARMOR)

#define _ARCHER_IRON_ARMOR_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 696, ARMOR)
#define _ARCHER_GOLDEN_ARMOR_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 696, ARMOR)
#define _ARCHER_DIAMOND_ARMOR_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 696, ARMOR)

#define _PURPLE_MAGE_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _PURPLE_MAGE_ARMOR_ITEM_, 648)
#define _RED_MAGE_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _RED_MAGE_ARMOR_ITEM_, 656)
#define _ENCHANTER_MAGE_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ENCHANTER_MAGE_ARMOR_ITEM_, 664)

#define _ARCHER_IRON_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ARCHER_IRON_ARMOR_ITEM_, 672)
#define _ARCHER_GOLDEN_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ARCHER_GOLDEN_ARMOR_ITEM_, 680)
#define _ARCHER_DIAMOND_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ARCHER_DIAMOND_ARMOR_ITEM_, 688)

#define _GEM_STAFF_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 408, WEAPON)
#define _ICE_STAFF_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 432, WEAPON)
#define _FIRE_STAFF_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 456, WEAPON)

#define _WOODEN_BOW_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 480, WEAPON)
#define _GOLDEN_BOW_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 504, WEAPON)
#define _AQUA_BOW_ITEM_ itemInit(stats(0, 0, 0, 0, 1), 528, WEAPON)

#define _GEM_STAFF_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _GEM_STAFF_ITEM_, 600)
#define _ICE_STAFF_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ICE_STAFF_ITEM_, 608)
#define _FIRE_STAFF_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _FIRE_STAFF_ITEM_, 616)

#define _WOODEN_BOW_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _WOODEN_BOW_ITEM_, 624)
#define _GOLDEN_BOW_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _GOLDEN_BOW_ITEM_, 632)
#define _AQUA_BOW_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _AQUA_BOW_ITEM_, 640)

#endif
