#include "../../../include/item/prototypes/dark_claymore.h"

void darkClaymoreUseCallback(Entity* _use_target, Room* _active_room) {
    Entity temp = *_use_target;

    switch (_use_target->facing) {
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
                entityKnockback(entity, _use_target->facing, 200);
                entityAttack(_use_target, entity);
            }
        }
    }
}
