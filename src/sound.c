#include "include/sound.h"

// Rates for traditional notes in octave +5
const u32 SOUND_RATES[12] = {
    8013, 7566, 7144, 6742, //C, C#, D, D#
    6362, 6005, 5666, 5345, //E, F, F#, G
    5048, 4766, 4499, 4246  //G#, A, A#, B
};

const u8 *NAMES[] = {"C ", "C#", "D ", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};

u32 getSoundRate(u32 note, u32 octave) {
    return (2048 - (SOUND_RATES[note] >> (4 + (octave))));
}

void notePlay(i32 note, i32 octave) {
    *_SOUND_1_FREQ_ = _SOUND_FREQ_RESET_ | getSoundRate(note, octave);
}
