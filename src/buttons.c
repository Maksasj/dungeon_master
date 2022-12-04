#include "include/buttons.h"

inline u8 buttonPressed(u16 _button) {
    u16 pressed = *_BUTTONS_ & _button;

    if (pressed == 0) {
        return 1;
    }

    return 0;
}
