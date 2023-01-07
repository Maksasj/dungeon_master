/**
 * sound
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows to manipulate with GBA sound system
*/

#ifndef _SOUND_H_
#define _SOUND_H_

#include "../utils/types.h"
#include "../utils/memory.h"
#include "../timer.h"
#include "interruption.h"

// Master sound enable and Sound 1-4 play status
#define _MASTER_SOUND_ ((vu16*) 0x4000084)
// Define to enable master sound
#define _SOUND_MASTER_ENABLE_ 0x80

// Direct Sound control and Sound 1-4 output ratio
#define _SOUND_CONTROL_ ((vu16*) 0x4000082)

// bit patterns for the sound control register
#define _SOUND_A_RIGHT_CHANNEL_     0x100
#define _SOUND_A_LEFT_CHANNEL_      0x200
#define _SOUND_A_FIFO_RESET_        0x800
#define _SOUND_B_RIGHT_CHANNEL_     0x1000
#define _SOUND_B_LEFT_CHANNEL_      0x2000
#define _SOUND_B_FIFO_RESET_        0x8000

// Direct Sound channel A samples 0-1
#define _FIFO_BUFFER_A_ ((vu8*) 0x40000A0)
// Direct Sound channel B samples 0-1
#define _FIFO_BUFFER_B_ ((vu8*) 0x40000A4)

// Sound 1-4 Output level and Stereo control
#define _SOUND_DMG_CONTROL_ ((vu16 *) 0x04000080)

// Sound 1 Frequency, reset and loop control
#define _SOUND_1_FREQ_  ((vu16 *) 0x04000064)
#define _SOUND_FREQ_RESET_  0x8000

// Sound 1-4 bits
#define _SDMG_SQR1_    0x01
#define _SDMG_SQR2_    0x02
#define _SDMG_WAVE_    0x04
#define _SDMG_NOISE_   0x08

// DMG ratio
#define _DIRECT_SOUND_DMG_25_   0
#define _DIRECT_SOUND_DMG_50_   0x0001
#define _DIRECT_SOUND_DMG_100_  0x0002

// Sound 1 Sweep control
#define _SOUND_1_SWEEP_ ((vu16 *) 0x04000060)

// No frequency sweep
#define _SOUND_SWEEP_OFF_ 0x0008

// Sound 1 Lenght, wave duty and envelope control
#define _SOUND_1_CONTROL_ ((vu16 *) 0x04000062)

// The duty cycle determines how the tone will sound
#define _SSQR_DUTY1_8_ 0      //12.5%  
#define _SSQR_DUTY1_4_ 0x0040 //25%
#define _SSQR_DUTY1_2_ 0x0080 //50%

#define _SDMG_BUILD_(_lmode, _rmode, _lvol, _rvol) \
    (((_lvol) & 7) | (((_rvol) & 7) << 4) | ((_lmode) << 8) | ((_rmode) << 12))

#define _SDMG_BUILD_LR_(_mode, _vol) _SDMG_BUILD_(_mode, _mode, _vol, _vol)

// the envelope is what determines how the sound will fade in/out
#define _SSQR_ENV_BUILD_(_ivol, _dir, _time) \
    (((_ivol) << 12) | ((_dir) << 11) | (((_time) & 7) << 8))

// Enum which holds the note indexes
typedef enum {
    NOTE_C = 0, NOTE_CIS,   NOTE_D,     NOTE_DIS,
    NOTE_E,     NOTE_F,     NOTE_FIS,   NOTE_G,
    NOTE_GIS,   NOTE_A,     NOTE_BES,   NOTE_B   
} ESoundNoteId;

/**
 * Initializes sound with the given volume, decay, max step time
 * 
 * @param   _output_vol         DMG volume
 * @param   _sound1_vol         Sound 1 volume
 * @param   _decay              Decay
 * @param   _max_step_time      Time
*/
void soundInit(u32 _output_vol, u32 _sound1_vol, u32 _decay, u32 _max_step_time);

/**
 * Function, that gets sound rate of the given note
 * 
 * @param   _note         note from ESoundNoteId
 * @param   _octave       octave
 * @return Sound rate
*/
u32 getSoundRate(u32 _note, u32 _octave);

/**
 * Function, that plays notes
 * 
 * @param   _note         note from ESoundNoteId
 * @param   _octave       octave
*/
void notePlay(i32 _note, i32 _octave);

/**
 * Function, that plays sounds
 * 
 * @param   _sound              sound
 * @param   _total_samples      total samples in bytes
 * @param   _sample_rate        rate
 * @param   _channel            channel 'A' - without sound looping, channel 'B' - with sound looping
*/
void playSound(i8* _sound, i32 _total_samples, i32 _sample_rate, i8 _channel);

/**
 * Interruption which checks to see if the sound has ended
*/
void onVBlank();

#endif
