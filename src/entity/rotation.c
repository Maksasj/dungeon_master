#include "../../include/entity/rotation.h"

Facing getOppositeFacing(Facing _facing) {
    switch (_facing) {
        case UP:
            return DOWN;
        case RIGHT:
            return LEFT;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
    }
}
