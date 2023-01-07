#ifndef TYPES_H
#define TYPES_H

#define NULL ((void *)0)

#define VELOCITY_CONSTANT 3
#define VELOCITY_SLOWDOWN_CONSTANT 1

#define POSITION_FIXED_SCALAR 5

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef volatile u8         vu8;
typedef volatile u16        vu16;
typedef volatile u32        vu32;
typedef volatile u64        vu64;

typedef signed char         i8;
typedef signed short        i16;
typedef signed long         i32;
typedef signed long long    i64;

typedef struct ivec2 {
    i32 x;
    i32 y;
} ivec2;

typedef struct ivec3 {
    i32 x;
    i32 y;
    i32 z;
} ivec3;

typedef struct fvec2 {
    float x;
    float y;
} fvec2;

typedef struct fvec3 {
    float x;
    float y;
    float z;
} fvec3;


inline ivec2 newIVec2(i32 _x, i32 _y);

inline ivec3 newIVec3(i32 _x, i32 _y, i32 _z);

inline fvec2 newFVec2(float _x, float _y);

inline fvec3 newFVec3(float _x, float _y, float _z);

#endif
