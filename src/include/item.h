#ifndef _ITEM_H_
#define _ITEM_H_

#include "entity/statblock.h"

#include "sprite.h"
#include "types.h"

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
    //Icon
    Sprite* sprite;
    SpriteSize sprite_size_in_pixels;
    
    fvec2 position;

    Item item;
} ItemDrop;

ItemDrop itemDropInit(fvec2 _position, Item item);

void itemDropInitSprite(ItemDrop* _itemDrop, Sprite _sprites[], i32* _next_sprite_index);

void itemDropUnloadSprite(ItemDrop *_itemDrop);

Item itemInit(Statblock _stat, u32 _sprite_offset, ItemType type);

#endif
