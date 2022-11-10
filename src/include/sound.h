#ifndef _SOUND_H_
#define _SOUND_H_

#include "types.h"

//Master sound enable and Sound 1-4 play status
#define _SOUND_CONTROL_ ((vu16 *) 0x0400084)
#define _MASTER_SOUND_ENABLE_ 0x80

//Direct Sound control and Sound 1-4 output ratio
#define _DIRECT_SOUND_CONTROL_ ((vu16 *) 0x0400082)

/* bit patterns for the sound control register */
#define _SOUND_A_RIGHT_CHANNEL_ 0x100
#define _SOUND_A_LEFT_CHANNEL_  0x200
#define _SOUND_A_FIFO_RESET_    0x800
#define _SOUND_B_RIGHT_CHANNEL_ 0x1000
#define _SOUND_B_LEFT_CHANNEL_  0x2000
#define _SOUND_B_FIFO_RESET_    0x8000

/* the location of where sound samples are placed for each channel */
#define _FIFO_BUFFER_A_ (vu8 *) 0x40000A0;
#define _FIFO_BUFFER_B_ (vu8 *) 0x40000A4;

#endif