#include "include/sound.h"

// Rates for traditional notes in octave +5
const u32 SOUND_RATES[12] = {
    8013, 7566, 7144, 6742, //C, C#, D, D#
    6362, 6005, 5666, 5345, //E, F, F#, G
    5048, 4766, 4499, 4246  //G#, A, A#, B
};

const u8 *NAMES[] = {"C ", "C#", "D ", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};

/* global variables to keep track of how much longer the sounds are to play */
u32 CHANNEL_A_VBLANKS_REMAINING = 0;
u32 CHANNEL_A_TOTAL_VBLANKS = 0;
u32 CHANNEL_B_VBLANKS_REMAINING = 0;

i8 *CURRENT_SOUND;

u32 getSoundRate(u32 _note, u32 _octave) {
    return (2048 - (SOUND_RATES[_note] >> (4 + (_octave))));
}

void notePlay(i32 _note, i32 _octave) {
    *_SOUND_1_FREQ_ = _SOUND_FREQ_RESET_ | getSoundRate(_note, _octave);
}

/* play a sound with a number of samples, and sample rate on one channel 'A' or 'B' */
void playSound(i8 *_sound, i32 _total_samples, i32 _sample_rate, i8 _channel) {
    CURRENT_SOUND = _sound;

    /* start by disabling the timer and dma controller (to reset a previous sound) */
    *_TIMER_0_CONTROL_ = 0;
    if (_channel == 'A') {
        *_DMA_1_CONTROL_ = 0;
    } else if (_channel == 'B') {
        *_DMA_2_CONTROL_ = 0; 
    }

    /* output to both sides and reset the FIFO */
    if (_channel == 'A') {
        *_DIRECT_SOUND_CONTROL_ |= _SOUND_A_RIGHT_CHANNEL_ | _SOUND_A_LEFT_CHANNEL_ | _SOUND_A_FIFO_RESET_;
    } else if (_channel == 'B') {
        *_DIRECT_SOUND_CONTROL_ |= _SOUND_B_RIGHT_CHANNEL_ | _SOUND_B_LEFT_CHANNEL_ | _SOUND_B_FIFO_RESET_;
    }

    /* set the dma channel to transfer from the sound array to the sound buffer */
    if (_channel == 'A') {
        *_DMA_1_SOURCE_ = (u32) _sound;
        *_DMA_1_DESTINATION_ = (u32) _FIFO_BUFFER_A_;
        *_DMA_1_CONTROL_ = _DMA_DESTINATION_FIXED_ | _DMA_REPEAT_ | _DMA_32_ | _DMA_SYNC_TO_TIMER_ | _DMA_ENABLE_;
    } else if (_channel == 'B') {
        *_DMA_2_SOURCE_ = (u32) _sound;
        *_DMA_2_DESTINATION_ = (u32) _FIFO_BUFFER_B_;
        *_DMA_2_CONTROL_ = _DMA_DESTINATION_FIXED_ | _DMA_REPEAT_ | _DMA_32_ | _DMA_SYNC_TO_TIMER_ | _DMA_ENABLE_;
    }

    /* set the timer so that it increments once each time a sample is due
     * we divide the clock (ticks/second) by the sample rate (samples/second)
     * to get the number of ticks/samples */
    vu16 ticks_per_sample = _CLOCK_ / _sample_rate;

    /* the timers all count up to 65536 and overflow at that point, so we count up to that
     * now the timer will trigger each time we need a sample, and cause DMA to give it one! */
    *_TIMER_0_DATA_ = 65536 - ticks_per_sample;

    /* determine length of playback in vblanks
     * this is the total number of samples, times the number of clock ticks per sample,
     * divided by the number of machine cycles per vblank (a constant) */
    if (_channel == 'A') {
        CHANNEL_A_VBLANKS_REMAINING = _total_samples * ticks_per_sample * (1.0 / _CYCLES_PER_BLANK_);
        CHANNEL_A_TOTAL_VBLANKS = CHANNEL_A_VBLANKS_REMAINING;
    } else if (_channel == 'B') {
        CHANNEL_B_VBLANKS_REMAINING = _total_samples * ticks_per_sample * (1.0 / _CYCLES_PER_BLANK_);
    }

    /* enable the timer */
    *_TIMER_0_CONTROL_ = _TIMER_ENABLE_ | _TIMER_FREQ_1_;
}

void onVBlank() {
    /* disable interrupts for now and save current state of interrupt */
    *_INTERRUPT_ENABLE_ = 0;
    u16 temp = *_INTERRUPT_STATE_;

    /* look for vertical refresh */
    if ((*_INTERRUPT_STATE_ & _INTERRUPT_VBLANK_) == _INTERRUPT_VBLANK_) {

        /* update channel A */
        if (CHANNEL_A_VBLANKS_REMAINING == 0) {
            /* restart the sound again when it runs out */
            CHANNEL_A_VBLANKS_REMAINING = CHANNEL_A_TOTAL_VBLANKS;
            *_DMA_1_CONTROL_ = 0;
            *_DMA_1_SOURCE_ = (u32)CURRENT_SOUND;
            *_DMA_1_CONTROL_ = _DMA_DESTINATION_FIXED_ | _DMA_REPEAT_ | _DMA_32_ | _DMA_SYNC_TO_TIMER_ | _DMA_ENABLE_;
        } else {
            --CHANNEL_A_VBLANKS_REMAINING;
        }

        /* update channel B */
        if (CHANNEL_B_VBLANKS_REMAINING == 0) {
            /* disable the sound and DMA transfer on channel B */
            *_SOUND_CONTROL_ &= ~(_SOUND_B_RIGHT_CHANNEL_ | _SOUND_B_LEFT_CHANNEL_ | _SOUND_B_FIFO_RESET_);
            *_DMA_2_CONTROL_ = 0;
        }
        else {
            --CHANNEL_B_VBLANKS_REMAINING;
        }
    }

    /* restore/enable interrupts */
    *_INTERRUPT_STATE_ = temp;
    *_INTERRUPT_ENABLE_ = 1;
}
