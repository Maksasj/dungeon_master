#include "../../include/entity/rotation.h"

Facing getOppositeFacing(Facing facing) {
    switch (facing) {
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
