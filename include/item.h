/**
 * Item
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains definition for all structure that are used to work with item system | item drop
*/

#ifndef _ITEM_H_
#define _ITEM_H_

#include "entity/statblock.h"

#include "sprite.h"
#include "utils/types.h"

/* Enum that defines basic item types */
typedef enum ItemType {
    ARMOR,
    WEAPON
} ItemType;

/* Structure that defines Item strucute */
typedef struct Item {
    /* Base stats of the item */
    Statblock base_stats;

    /* Sprite offset in the global spritesheet*/
    u32 sprite_offset;

    /* Type of the item */
    ItemType type;

    /* Count of the item in the item stack */
    i8 count;
} Item;

/* Structure that defines Item Drop strucute, used for rendering lying down on the ground and other.. */
typedef struct ItemDrop {
    /* Pointer to the sprite of the this item drop entity */
    Sprite* sprite;

    /* Size of the sprite */
    SpriteSize sprite_size_in_pixels;

    /* Position of the this Item drop entity */
    ivec2 position;

    /* Sprite offset in the global spritesheet*/
    u32 sprite_offset;

    /* Item that cotains this Item drop entity */
    Item item;
} ItemDrop;

/**
 * Function that initializes item drop entity
 * 
 * @param   _position  Position of the Item drop enity
 * @param   _item Item it self
 * @param   _sprite_offset  Offset in the global spritesheet
 * @return           Instance of the Item Drop entity
*/
ItemDrop itemDropInit(ivec2 _position, Item _item, u32 _sprite_offset);

/**
 * Initializes sprite for the give item drop entity
 * 
 * @param   _itemDrop  Pointer to item drop instance
 * @param   _sprites  Pointer to main sprite array
 * @param   _next_sprite_index Pointer to variable that stores last loaded sprite index   
*/
void itemDropInitSprite(ItemDrop* _itemDrop, Sprite _sprites[], i32* _next_sprite_index);

/**
 * Unloades sprite of the given item drop entity
 * 
 * @param   _itemDrop  Pointer to item drop instance
*/
void itemDropUnloadSprite(ItemDrop *_itemDrop);

/**
 * Initializes sprite for the give item drop entity
 * 
 * @param   _stat  Base stats of the item
 * @param   _sprite_offset  Offset in the global spritesheet
 * @param   _type Type of the item
 * @return  Item instance
*/
Item itemInit(Statblock _stat, u32 _sprite_offset, ItemType _type);

/* Macros for all items in the game */
#define _IRON_CHESTPLATE_ITEM_ itemInit(statsInit(0, 0, 0, 0, 1), 112, ARMOR)
#define _GOLDEN_CHESTPLATE_ITEM_ itemInit(statsInit(1, 0, 0, 0, 2), 136, ARMOR)
#define _DIAMOND_CHESTPLATE_ITEM_ itemInit(statsInit(2, 0, 0, 0, 3), 160, ARMOR)

#define _SHORT_SWORD_ITEM_ itemInit(statsInit(0, 0, 0, 1, 0), 184, WEAPON)
#define _DARK_CLAYMORE_ITEM_ itemInit(statsInit(0, 0, 0, 2, 0), 208, WEAPON)
#define _ICE_SWORD_ITEM_ itemInit(statsInit(0, 1, 0, 1, 0), 232, WEAPON)

#define _PURPLE_MAGE_ARMOR_ITEM_ itemInit(statsInit(0, 0, 0, 0, 1), 336, ARMOR)
#define _RED_MAGE_ARMOR_ITEM_ itemInit(statsInit(1, 0, 1, 0, 1), 360, ARMOR)
#define _ENCHANTER_MAGE_ARMOR_ITEM_ itemInit(statsInit(2, 0, 1, 0, 2), 384, ARMOR)

#define _ARCHER_IRON_ARMOR_ITEM_ itemInit(statsInit(0, 0, 0, 0, 1), 768, ARMOR)
#define _ARCHER_GOLDEN_ARMOR_ITEM_ itemInit(statsInit(1, 1, 0, 0, 1), 768, ARMOR)
#define _ARCHER_DIAMOND_ARMOR_ITEM_ itemInit(statsInit(2, 1, 0, 0, 2), 768, ARMOR)

#define _GEM_STAFF_ITEM_ itemInit(statsInit(0, 0, 1, 0, 0), 408, WEAPON)
#define _ICE_STAFF_ITEM_ itemInit(statsInit(0, 0, 2, 0, 0), 432, WEAPON)
#define _FIRE_STAFF_ITEM_ itemInit(statsInit(0, 0, 3, 0, 0), 456, WEAPON)

#define _WOODEN_BOW_ITEM_ itemInit(statsInit(0, 1, 0, 0, 0), 480, WEAPON)
#define _GOLDEN_BOW_ITEM_ itemInit(statsInit(0, 2, 0, 0, 0), 504, WEAPON)
#define _AQUA_BOW_ITEM_ itemInit(statsInit(0, 3, 0, 0, 0), 528, WEAPON)

/* Macros for all item drops in the game */
#define _IRON_CHESTPLATE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _IRON_CHESTPLATE_ITEM_, 280)
#define _GOLDEN_CHESTPLATE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _GOLDEN_CHESTPLATE_ITEM_, 288)
#define _DIAMOND_CHESTPLATE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _DIAMOND_CHESTPLATE_ITEM_, 296)

#define _SHORT_SWORD_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _SHORT_SWORD_ITEM_, 256)
#define _DARK_CLAYMORE_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _DARK_CLAYMORE_ITEM_, 264)
#define _ICE_SWORD_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ICE_SWORD_ITEM_, 272)

#define _PURPLE_MAGE_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _PURPLE_MAGE_ARMOR_ITEM_, 648)
#define _RED_MAGE_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _RED_MAGE_ARMOR_ITEM_, 656)
#define _ENCHANTER_MAGE_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ENCHANTER_MAGE_ARMOR_ITEM_, 664)

#define _ARCHER_IRON_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ARCHER_IRON_ARMOR_ITEM_, 672)
#define _ARCHER_GOLDEN_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ARCHER_GOLDEN_ARMOR_ITEM_, 680)
#define _ARCHER_DIAMOND_ARMOR_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ARCHER_DIAMOND_ARMOR_ITEM_, 688)

#define _GEM_STAFF_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _GEM_STAFF_ITEM_, 600)
#define _ICE_STAFF_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _ICE_STAFF_ITEM_, 608)
#define _FIRE_STAFF_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _FIRE_STAFF_ITEM_, 616)

#define _WOODEN_BOW_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _WOODEN_BOW_ITEM_, 624)
#define _GOLDEN_BOW_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _GOLDEN_BOW_ITEM_, 632)
#define _AQUA_BOW_ITEM_DROP_(X, Y) itemDropInit(newIVec2(X, Y), _AQUA_BOW_ITEM_, 640)

#endif
