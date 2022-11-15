#ifndef _SOUND_H_
#define _SOUND_H_

#include "types.h"

//Master sound enable and Sound 1-4 play status
#define _SOUND_CONTROL_ ((vu16 *) 0x04000084)
#define _MASTER_SOUND_ENABLE_ 0x80

//Direct Sound control and Sound 1-4 output ratio
#define _DIRECT_SOUND_CONTROL_ ((vu16 *) 0x04000082)

//Tone generators at 25%, 50%, 100% volume.
#define _DIRECT_SOUND_DMG_25_   0
#define _DIRECT_SOUND_DMG_50_   0x0001
#define _DIRECT_SOUND_DMG_100_  0x0002

/* bit patterns for the sound control register */
#define _SOUND_A_RIGHT_CHANNEL_ 0x100
#define _SOUND_A_LEFT_CHANNEL_  0x200
#define _SOUND_A_FIFO_RESET_    0x800
#define _SOUND_B_RIGHT_CHANNEL_ 0x1000
#define _SOUND_B_LEFT_CHANNEL_  0x2000
#define _SOUND_B_FIFO_RESET_    0x8000

//Sound 1 frequency control
#define _SOUND_1_FREQ_  ((vu16 *) 0x04000064)

//Sound 1 Lenght, wave duty and envelope control
#define _SOUND_1_CONTROL_ ((vu16 *) 0x04000062)

//Sound 1 Sweep control
#define _SOUND_1_SWEEP_ ((vu16 *) 0x04000060)

//Disable sweep altogether.
#define _SOUND_SWEEP_OFF_ 0x0008

//Reset sound
#define _SOUND_FREQ_RESET_  0x8000

//50% duty cycle
#define _SSQR_DUTY1_2_ 0x0080

/* the location of where sound samples are placed for each channel */
#define _FIFO_BUFFER_A_ ((vu8 *) 0x400000A0)
#define _FIFO_BUFFER_B_ ((vu8 *) 0x400000A4)

//Sound 1-4 Output level and Stereo control
#define _SOUND_DMG_CONTROL_ ((vu16 *) 0x04000080)

#define _SDMG_SQR1_    0x01
#define _SDMG_SQR2_    0x02
#define _SDMG_WAVE_    0x04
#define _SDMG_NOISE_   0x08

#define _SDMG_BUILD_(_lmode, _rmode, _lvol, _rvol) (((_lvol) & 7) | (((_rvol) & 7 ) << 4) | ((_lmode) << 8) | ((_rmode) << 12))

#define _SDMG_BUILD_LR_(_mode, _vol) _SDMG_BUILD_(_mode, _mode, _vol, _vol)

#define _SSQR_ENV_BUILD_(_ivol, _dir, _time) (((_ivol) << 12) | ((_dir) << 11) | (((_time) & 7) << 8))

typedef enum {
    NOTE_C = 0, NOTE_CIS,   NOTE_D,     NOTE_DIS,
    NOTE_E,     NOTE_F,     NOTE_FIS,   NOTE_G,
    NOTE_GIS,   NOTE_A,     NOTE_BES,   NOTE_B   
} ESoundNoteId;

u32 getSoundRate(u32 note, u32 octave);

void notePlay(i32 note, i32 octave);

#endif
