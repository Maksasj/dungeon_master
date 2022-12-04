#include "include/sound.h"

// Rates for traditional notes in octave +5
const u32 SOUND_RATES[12] = {
    8013, 7566, 7144, 6742,         /*  C, C#, D, D#  */
    6362, 6005, 5666, 5345,         /*  E, F, F#, G   */
    5048, 4766, 4499, 4246          /*  G#, A, A#, B  */
};

const u8 *NAMES[] = {"C ", "C#", "D ", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};

/* global variables to keep track of how much longer the sounds are to play */
u32 CHANNEL_A_VBLANKS_REMAINING = 0;
u32 CHANNEL_A_TOTAL_VBLANKS = 0;
u32 CHANNEL_B_VBLANKS_REMAINING = 0;

i8 *CURRENT_A_SOUND;

void soundInit(u32 _output_vol, u32 _sound1_vol, u32 _decay, u32 _max_step_time) {
    *_MASTER_SOUND_ = _SOUND_MASTER_ENABLE_;
    *_SOUND_DMG_CONTROL_ = _SDMG_BUILD_LR_(_SDMG_SQR1_, _output_vol);
    *_SOUND_CONTROL_ = _DIRECT_SOUND_DMG_100_;

    *_SOUND_1_SWEEP_ = _SOUND_SWEEP_OFF_;

    *_SOUND_1_CONTROL_ = _SSQR_ENV_BUILD_(_sound1_vol, _decay, _max_step_time) | _SSQR_DUTY1_2_;
    *_SOUND_1_FREQ_ = 0;
}

u32 getSoundRate(u32 _note, u32 _octave) {
    return (2048 - (SOUND_RATES[_note] >> (4 + (_octave))));
}

void notePlay(i32 _note, i32 _octave) {
    *_SOUND_1_FREQ_ = _SOUND_FREQ_RESET_ | getSoundRate(_note, _octave);
}

void playSound(i8* _sound, i32 _total_samples, i32 _sample_rate, i8 _channel) {
    *_TIMER_0_CONTROL_ = 0;
    if (_channel == 'A') {
        CURRENT_A_SOUND = _sound;
        *_DMA_1_CONTROL_ = 0;
    } else if (_channel == 'B') {
        *_DMA_2_CONTROL_ = 0; 
    }

    if (_channel == 'A') {
        *_SOUND_CONTROL_ |= _SOUND_A_RIGHT_CHANNEL_ | _SOUND_A_LEFT_CHANNEL_ | _SOUND_A_FIFO_RESET_;
    } else if (_channel == 'B') {
        *_SOUND_CONTROL_ |= _SOUND_B_RIGHT_CHANNEL_ | _SOUND_B_LEFT_CHANNEL_ | _SOUND_B_FIFO_RESET_;
    }

    *_MASTER_SOUND_ = _SOUND_MASTER_ENABLE_;

    if (_channel == 'A') {
        *_DMA_1_SOURCE_ = (u32) _sound;
        *_DMA_1_DESTINATION_ = (u32) _FIFO_BUFFER_A_;
        *_DMA_1_CONTROL_ = _DMA_DESTINATION_FIXED_ | _DMA_REPEAT_ | _DMA_32_ | _DMA_SYNC_TO_TIMER_ | _DMA_ENABLE_;
    } else if (_channel == 'B') {
        *_DMA_2_SOURCE_ = (u32) _sound;
        *_DMA_2_DESTINATION_ = (u32) _FIFO_BUFFER_B_;
        *_DMA_2_CONTROL_ = _DMA_DESTINATION_FIXED_ | _DMA_REPEAT_ | _DMA_32_ | _DMA_SYNC_TO_TIMER_ | _DMA_ENABLE_;
    }

    u16 ticks_per_sample = _CLOCK_ / _sample_rate;

    *_TIMER_0_DATA_ = 65536 - ticks_per_sample;

    if (_channel == 'A') {
        CHANNEL_A_VBLANKS_REMAINING = _total_samples * ticks_per_sample * (1.0 / _CYCLES_PER_BLANK_);
        CHANNEL_A_TOTAL_VBLANKS = CHANNEL_A_VBLANKS_REMAINING;
    } else if (_channel == 'B') {
        CHANNEL_B_VBLANKS_REMAINING = _total_samples * ticks_per_sample * (1.0 / _CYCLES_PER_BLANK_);
    }

    *_TIMER_0_CONTROL_ = _TIMER_ENABLE_ | _TIMER_FREQ_1_;
}

void onVBlank() {
    *_INTERRUPT_ENABLE_ = 0;
    u16 temp = *_INTERRUPT_STATE_;

    if ((*_INTERRUPT_STATE_ & _INT_VBLANK_) == _INT_VBLANK_) {

        if (CHANNEL_A_VBLANKS_REMAINING == 0) {
            CHANNEL_A_VBLANKS_REMAINING = CHANNEL_A_TOTAL_VBLANKS;
            *_DMA_1_CONTROL_ = 0;
            *_DMA_1_SOURCE_ = (u32) CURRENT_A_SOUND;
            *_DMA_1_CONTROL_ = _DMA_DESTINATION_FIXED_ | _DMA_REPEAT_ | _DMA_32_ |
                _DMA_SYNC_TO_TIMER_ | _DMA_ENABLE_;
        } else {
            --CHANNEL_A_VBLANKS_REMAINING;
        }

        if (CHANNEL_B_VBLANKS_REMAINING == 0) {
            *_SOUND_CONTROL_ &= ~(_SOUND_B_RIGHT_CHANNEL_ | _SOUND_B_LEFT_CHANNEL_ | _SOUND_B_FIFO_RESET_);
            *_DMA_2_CONTROL_ = 0;
        }
        else {
            --CHANNEL_B_VBLANKS_REMAINING;
        }
    }

    *_INTERRUPT_STATE_ = temp;
    *_INTERRUPT_ENABLE_ = 1;
}
