#include "../../../include/entity/prototypes/player.h"

const static i32 GRID_LENGTH = 12;
const static i32 GRID_HEIGHT = 7;

void initPlayerSpec(Sprite* _sprites, i32* _next_sprite_index, Entity* _entity, PlayerSpecData* _pspec, Class _chosenClass) {
    _pspec->armor = spriteInit(
        _sprites, 
        _next_sprite_index, 
        _entity->position.x >> _POSITION_FIXED_SCALAR_, 
        _entity->position.y >> _POSITION_FIXED_SCALAR_, 
        SIZE_16_16, 
        0, 0, 0, 2);
    
    _pspec->weapon = spriteInit(
        _sprites, 
        _next_sprite_index, 
        _entity->position.x >> _POSITION_FIXED_SCALAR_, 
        _entity->position.y >> _POSITION_FIXED_SCALAR_, 
        SIZE_16_16, 
        0, 0, 0, 2);

    _pspec->itemUIIcon = spriteInit(
        _sprites, 
        _next_sprite_index, 
        220 + 28, 45,
        SIZE_16_16, 
        0, 0, 0, 0);

    spritePosition(_pspec->armor, -64, -64);
    spritePosition(_pspec->weapon, -64, -64);

    _pspec->sprites = _sprites;
    _pspec->next_sprite_index = _next_sprite_index;
    
    _pspec->class = _chosenClass;

    _pspec->hand_slot.count = 0;
    _pspec->armor_slot.count = 0;
}

void putOnItem(Entity *player, Item item) {
    PlayerSpecData* pspec = (PlayerSpecData*) player->spec;

    if(item.type == ARMOR) {
        pspec->armor_slot = item;
        pspec->armor_slot.count = 1;
        spriteSetOffset(pspec->armor, pspec->armor_slot.sprite_offset);
    }

    if(item.type == WEAPON) {
        pspec->hand_slot = item;
        pspec->hand_slot.count = 1;
        spriteSetOffset(pspec->weapon, pspec->hand_slot.sprite_offset);
    }
}

void updatePlayerSpec(PlayerSpecData* _pspec, Entity *_entity) {
    i32 offset_x = 0;
    i8 flip = 0;

    if(_entity->facing == RIGHT) {
        offset_x = 16;
    } else if(_entity->facing == LEFT) {
        offset_x = 16;
        flip = 1;
    } else if(_entity->facing == DOWN) {
        offset_x = 8;
    }

    if(_pspec->hand_slot.count != 0) {
        spritePosition(
            _pspec->weapon, 
            _entity->position.x >> _POSITION_FIXED_SCALAR_, 
            _entity->position.y >> _POSITION_FIXED_SCALAR_);

        spriteSetOffset(_pspec->weapon, _pspec->hand_slot.sprite_offset + offset_x);
        spriteSetHorizontalFlip(_pspec->weapon, flip);
    }

    if(_pspec->armor_slot.count != 0) {
        spritePosition(
            _pspec->armor, 
            _entity->position.x >> _POSITION_FIXED_SCALAR_,
            _entity->position.y >> _POSITION_FIXED_SCALAR_);

        spriteSetOffset(_pspec->armor, _pspec->armor_slot.sprite_offset + offset_x);
        spriteSetHorizontalFlip(_pspec->armor, flip);
    }

    vu16* uiLayer = screenBlock(0);

    i32 player_max_health =  
        _entity->base_stats.stamina + 
        _pspec->armor_slot.base_stats.stamina + 
        _pspec->hand_slot.base_stats.stamina;

    int h;
    for(h = 0; h < player_max_health; ++h) {
        char healthIcon = 55;
        if(h >= _entity->health) healthIcon = 56;

        uiLayer[33 + (h % HEALTH_PER_ROW) + 32*(h / HEALTH_PER_ROW)] = healthIcon;
    }

    i32 player_armor = 
        _entity->base_stats.armor + 
        _pspec->armor_slot.base_stats.armor + 
        _pspec->hand_slot.base_stats.armor;

    for(h = 0; h < player_armor; ++h) {
        const char shieldIcon = 57;
        uiLayer[60 - (h % HEALTH_PER_ROW) + 32*(h / HEALTH_PER_ROW)] = shieldIcon;
    }

    uiLayer[577] = 58;
    uiLayer[545] = 59;

    i32 calculated_damage = (*_entity->calculate_damage_callback)(_entity);;

    i32 hundredDigit = calculated_damage / 100;
    i32 tensDigit = (calculated_damage / 10) - hundredDigit*10;
    i32 unitsDigit = calculated_damage - hundredDigit * 100 - tensDigit * 10;

    i8 charShift = 0;
    
    if(calculated_damage > 9)
        charShift++;

    if(calculated_damage > 99)
        charShift++;

    uiLayer[578] = 344;
    
    if(calculated_damage > 99)
        uiLayer[577 + charShift] = 272 + hundredDigit;
    
    if(calculated_damage > 9)
        uiLayer[578 + charShift] = 272 + tensDigit;
    
    uiLayer[579 + charShift] = 272 + unitsDigit;
}

i32 playerTryDodge(Entity* _self) {
    PlayerSpecData* pspec = (PlayerSpecData*)_self->spec;
    Item *hand = &pspec->hand_slot;
    Item *armor = &pspec->armor_slot;
    
    i32 agility = _self->base_stats.agility + hand->base_stats.agility + armor->base_stats.agility;
    
    if (agility < 0)
        agility = 0;
    
    u32 random_number = random((u32)_self->position.x * (u32)_self->position.y) % 101;

    if (random_number < _DODGE_CHANCE_FROM_AGILITY_ * agility) {
        return 1;
    }

    return 0;
}

void killPlayer(Entity* _self) {
    //TODO: restart the game
    return;
}

void player_update(Entity* _self, World* _world, Room* _room) {
    ivec2 world_position = screenToWorldPosition(_self->position);

    _self->vel.x = _DIV2_(_self->vel.x);
    _self->vel.y = _DIV2_(_self->vel.y);

    PlayerSpecData* pspec = (PlayerSpecData*) _self->spec;
    updatePlayerSpec(pspec, _self);

    i32 base_sprite_offset = 0;

    switch (pspec->class) {
        case WARRIOR:
            base_sprite_offset = 0;
            break;
        case WIZARD:
            base_sprite_offset = 744;
            break;
        case ARCHER:
            base_sprite_offset = 768;
            break;
        default:
            break;
    }

    if (world_position.x < 0)
        _self->vel.x = 10;
    else if (world_position.x > GRID_LENGTH)
        _self->vel.x = -10;
    else if (world_position.y < 0)
        _self->vel.y = 10;
    else if (world_position.y > GRID_HEIGHT)
       _self->vel.y = -10;
    
    if (buttonPressed(_BUTTON_RIGHT_)) {
        _self->vel.x += VELOCITY_CONSTANT;
        
        _self->facing = RIGHT;
        spriteSetOffset(_self->sprite, base_sprite_offset + 16);
        spriteSetHorizontalFlip(_self->sprite, 0);
    }

    if (buttonPressed(_BUTTON_LEFT_)) {
        _self->vel.x -= VELOCITY_CONSTANT;

        _self->facing = LEFT;
        spriteSetOffset(_self->sprite, base_sprite_offset + 16);
        spriteSetHorizontalFlip(_self->sprite, 1);
    }

    if (buttonPressed(_BUTTON_DOWN_)) {
        _self->vel.y += VELOCITY_CONSTANT;

        _self->facing = DOWN;
        spriteSetOffset(_self->sprite, base_sprite_offset + 8);
    }

    if (buttonPressed(_BUTTON_UP_)) {
        _self->vel.y -= VELOCITY_CONSTANT;

        _self->facing = UP;
        spriteSetOffset(_self->sprite, base_sprite_offset + 0);
    }
    
    if (buttonPressed(_BUTTON_A_)) {
        if (_self->item_use_cooldown == 0) {
            if(pspec->hand_slot.count != 0)
                (pspec->hand_slot.use_item_callback)(_self, _room);
            
            _self->item_use_cooldown = 100;
        }
    }

    CollisionType xCol = worldCollision(_world, newIVec2((_self->position.x >> _POSITION_FIXED_SCALAR_) + _self->vel.x, (_self->position.y >> _POSITION_FIXED_SCALAR_)));
    if(xCol == NONE || xCol == OPENED_DOOR || xCol == NEXT_FLOOR_ENTRANCE || xCol == TRAP) {
        _self->position.x += _self->vel.x;
    }

    CollisionType yCol = worldCollision(_world, newIVec2((_self->position.x >> _POSITION_FIXED_SCALAR_), (_self->position.y >> _POSITION_FIXED_SCALAR_) + _self->vel.y));
    if(yCol == NONE || yCol == OPENED_DOOR || yCol == NEXT_FLOOR_ENTRANCE || yCol == TRAP) {
        _self->position.y += _self->vel.y;
    }

    #ifndef _GOD_MODE_
    if(xCol == TRAP || yCol == TRAP) {
        if (!_self->invulnerable) {
            entityTakeDamage(_self, 1);
            makeInvulnerable(_self);
        }
    }
    #endif

    if(xCol == OPENED_DOOR || yCol == OPENED_DOOR) {
        (*pspec->next_sprite_index) = _RESERVED_SPRITE_AMOUNT_;

        _SMOOTH_PALETT_TRANSITION_TO_BLACK_;

        if((_self->position.y >> 3) < 70) {
            _self->position = newIVec2((_SCREEN_WIDTH_ / 2 - 8) << _POSITION_FIXED_SCALAR_, 128 << _POSITION_FIXED_SCALAR_); 
            nextRoom(_world, pspec->sprites, pspec->next_sprite_index);
        } else {
            _self->position = newIVec2((_SCREEN_WIDTH_ / 2 - 8) << _POSITION_FIXED_SCALAR_, 18 << _POSITION_FIXED_SCALAR_);
            backRoom(_world, pspec->sprites, pspec->next_sprite_index);
        }

        _self->health =  
            _self->base_stats.stamina + 
            pspec->armor_slot.base_stats.stamina + 
            pspec->hand_slot.base_stats.stamina;
    
        #ifdef _LIGHT_ON_
            //Reload light
            vu16* pointer = screenBlock(2);
            int x;
            int y;
            
            for(x = 0; x < 30; ++x)
                for(y = 0; y < 20; ++y)
                    pointer[x + 32*y] = 0x17;
        #endif

        room_switch = 1;
    } else if (xCol == NEXT_FLOOR_ENTRANCE || yCol == NEXT_FLOOR_ENTRANCE) {
        (*pspec->next_sprite_index) = _RESERVED_SPRITE_AMOUNT_;
        _self->position = newIVec2((_SCREEN_WIDTH_ / 2 - 8) << _POSITION_FIXED_SCALAR_, (_SCREEN_HEIGHT_ / 2 - 8) << _POSITION_FIXED_SCALAR_);

        _SMOOTH_PALETT_TRANSITION_TO_BLACK_;

        generateFloor(_world, pspec->class);

        #ifdef _LIGHT_ON_
            //Reload light
            vu16* pointer = screenBlock(2);
            int x;
            int y;
            
            for(x = 0; x < 30; ++x)
                for(y = 0; y < 20; ++y)
                    pointer[x + 32*y] = 0x17;
        #endif
        
        floor_switch = 1;
        gotoRoom(_world, 0, pspec->sprites, pspec->next_sprite_index);
    }

    if (_self->invulnerable) {
        if (_self->invulnerability_time > 0) {
            --_self->invulnerability_time;
        } else {
            _self->invulnerable = 0;
        }
    }
}
