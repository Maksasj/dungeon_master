#include "include/buttons.h"

inline u8 buttonPressed(u16 _button) {
    /* and the button register with the button constant we want */
    u16 pressed = *_BUTTONS_ & _button;

    /* if this value is zero, then it's not pressed */
    if (pressed == 0) {
        return 1;
    }

    return 0;
}
