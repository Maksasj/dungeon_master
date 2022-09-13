#ifndef VEC_H
#define VEC_H

#include "u.h"

typedef struct {
    float x;
    float y;
} fvec2;

typedef struct {
    float x;
    float y;
    float z;
} fvec3;

fvec2 vec2F(float x, float y) {
    fvec2 vec = {x, y};
    return vec;
}

fvec3 vec3F(float x, float y, float z) {
    fvec3 vec = {x, y, z};
    return vec;
}

// Vector with natural number just more optimised for complex computations
typedef struct {
    u16 x;
    u16 y;
} ivec2;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} ivec3;

ivec2 vec2I(u16 x, u16 y) {
    ivec2 vec = {x, y};
    return vec;
}

ivec3 vec3I(u16 x, u16 y, u16 z) {
    ivec3 vec = {x, y, z};
    return vec;
}

#endif
