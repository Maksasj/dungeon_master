#include "include/item.h"

ItemDrop itemDropInit(fvec2 _position, Item item) {
    ItemDrop _itemDrop;

    _itemDrop.position = _position;

    _itemDrop.item = item;

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

void itemDropInitSprite(ItemDrop* _itemDrop, Sprite _sprites[], i32* _next_sprite_index) {
    _itemDrop->sprite = spriteInit(_sprites, _next_sprite_index, _itemDrop->position.x, _itemDrop->position.y, SIZE_16_16, 0, 0, 0, 1);
    _itemDrop->sprite_size_in_pixels = SIZE_16_16;
}

void itemDropUnloadSprite(ItemDrop *_itemDrop) {
    spritePosition(_itemDrop->sprite, -64, -64);
    _itemDrop->sprite = NULL;
}
