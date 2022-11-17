#ifndef TYPES_H
#define TYPES_H

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
    int x;
    int y;
} ivec2;

ivec2 newIVec2(int x, int y);

typedef struct ivec3 {
    int x;
    int y;
    int z;
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

#endif
