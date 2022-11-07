#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include "types.h"

/* the button register holds the bits which indicate whether each button has
 * been pressed - this has got to be volatile as well
 */
#define _BUTTONS_ ((vu16*) 0x04000130)

u8 buttonPressed(u16 _button);

#endif
