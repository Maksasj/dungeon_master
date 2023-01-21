#include "../../../include/entity/prototypes/warrior.h"

void warriorAttack(Entity* _warrior, Room* _active_room) {
    Entity temp = *_warrior;

    switch (_warrior->facing) {
        case RIGHT:
            temp.position.x += _ATTACK_OFFSET_;
            break;
        case LEFT:
            temp.position.x -= _ATTACK_OFFSET_;
            break;
        case DOWN:
            temp.position.y += _ATTACK_OFFSET_;
            break;
        case UP:
            temp.position.y -= _ATTACK_OFFSET_;
            break;
        default:
            break;
    }

    i32 i;
    for(i = 0; i < _active_room->current_entity_count; ++i) {
        Entity *entity = &_active_room->entity_pool[i];

        if ((*entity->on_collision_enter)(entity, &temp)) {
            if (!(*entity->dodge_callback)(entity)) {
                entityKnockback(entity, _warrior->facing, 200);
                entityAttack(_warrior, entity);
            }
        }
    }
}

i32 warriorCalculateDamage(Entity* _warrior) {
    PlayerSpecData* pspec = (PlayerSpecData*)_warrior->spec;
    Item *hand = &pspec->hand_slot;
    Item *armor = &pspec->armor_slot;

    i32 strenght = _warrior->base_stats.strength + hand->base_stats.strength + armor->base_stats.strength;

    if (strenght < 0) {
        strenght = 0;
    }

    return 1 + strenght;
}
