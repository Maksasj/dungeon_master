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
#define _ICE_SWORD_ITEM_DROP(X, Y) itemDropInit(newIVec2(X, Y), _ICE_SWORD_ITEM_, 272)

#endif
