#include "../../include/item/item.h"

ItemDrop itemDropInit(ivec2 _position, Item item, u32 _sprite_offset) {
    ItemDrop _itemDrop;

    _itemDrop.position.x = _position.x << _POSITION_FIXED_SCALAR_;
    _itemDrop.position.y = _position.y << _POSITION_FIXED_SCALAR_;

    _itemDrop.item = item;
    _itemDrop.item.drop_sprite_offset = _sprite_offset;

    _itemDrop.sprite_offset = _sprite_offset;

    return _itemDrop;
}

Item itemInit(Statblock _stat, u32 _sprite_offset, ItemType type) {
    Item item;

    item.type = type;
    item.base_stats = _stat;
    item.sprite_offset = _sprite_offset;
    item.count = 1;

    return item;
}

Item itemReload(Item _self) {
    _self.count = 1;

    return _self;
}

void itemDropInitSprite(ItemDrop* _itemDrop, Sprite _sprites[], i32* _next_sprite_index) {
    _itemDrop->sprite = spriteInit(
        _sprites, 
        _next_sprite_index, 
        _itemDrop->position.x >> _POSITION_FIXED_SCALAR_, 
        _itemDrop->position.y >> _POSITION_FIXED_SCALAR_, 
        SIZE_16_16, 
        0, 0, 0, 3);
        
    _itemDrop->sprite_size_in_pixels = SIZE_16_16;
    spriteSetOffset(_itemDrop->sprite, _itemDrop->sprite_offset);
}

void itemDropUnloadSprite(ItemDrop *_itemDrop) {
    spritePosition(_itemDrop->sprite, -64, -64);
    _itemDrop->sprite = NULL;
}
