#include "../../include/utils/random.h"

u32 RAND_NEXT = 15485863;

u32 random() {
    RAND_NEXT = RAND_NEXT * 1103515245 + 12345;
    return (u32)(RAND_NEXT/65536) % 32768;
}

void setSeed(u32 _seed) {
    RAND_NEXT = _seed;
}

inline u32 getRandomInRange(u32 min, u32 max) {
    return (random() % (max - min + 1)) + min;
}
