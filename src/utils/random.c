#include "../../include/utils/random.h"

u32 SEED = 15485863;

u32 random(u32 _seed) {
    SEED -= _seed >> 2;

    SEED ^= _seed << 13;
    SEED ^= _seed >> 17;
    SEED ^= _seed << 5;

    return SEED;
}
