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

#include "../entity/statblock.h"

#include "../sprite.h"
#include "../utils/types.h"

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

    /* Item use callback */
    //void (*use_item_callback)(Entity* _use_target, Room* _active_room);
    void (*use_item_callback)(void*, void*);
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

Item itemReload(Item _item);

#endif
