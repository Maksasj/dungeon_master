/**
 * types
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Custom types
*/

#ifndef TYPES_H
#define TYPES_H

// null pointer
#define NULL ((void *)0)

// acceleration constant
#define _VELOCITY_CONSTANT_ 4

// deceleration constant
#define VELOCITY_SLOWDOWN_CONSTANT 1

// constant, which works with fixed point calculations
#define _POSITION_FIXED_SCALAR_ 5

// typedefs to reduce the names of existing types
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

// typedefs to reduce the names of existing types
typedef volatile u8         vu8;
typedef volatile u16        vu16;
typedef volatile u32        vu32;
typedef volatile u64        vu64;

// typedefs to reduce the names of existing types
typedef signed char         i8;
typedef signed short        i16;
typedef signed long         i32;
typedef signed long long    i64;

// Vector2 (x, y)
typedef struct ivec2 {
    i32 x;
    i32 y;
} ivec2;

// Vector3 (x, y, z)
typedef struct ivec3 {
    i32 x;
    i32 y;
    i32 z;
} ivec3;

// float Vector2 (x, y)
typedef struct fvec2 {
    float x;
    float y;
} fvec2;

// float Vector3 (x, y, z)
typedef struct fvec3 {
    float x;
    float y;
    float z;
} fvec3;

/**
 * Creates Vector2
 * 
 * @param _x    x coordinate
 * @param _y    y coordinate
 * 
 * @return Vector2 type
*/
inline ivec2 newIVec2(i32 _x, i32 _y);

/**
 * Creates Vector3
 * 
 * @param _x    x coordinate
 * @param _y    y coordinate
 * @param _z    z coordinate
 * 
 * @return Vector3 type
*/
inline ivec3 newIVec3(i32 _x, i32 _y, i32 _z);

/**
 * Creates float Vector2
 * 
 * @param _x    x float coordinate
 * @param _y    y float coordinate
 * 
 * @return float Vector2 type
*/
inline fvec2 newFVec2(float _x, float _y);

/**
 * Creates Vector3
 * 
 * @param _x    float x coordinate
 * @param _y    float y coordinate
 * @param _z    float z coordinate
 * 
 * @return float Vector3 type
*/
inline fvec3 newFVec3(float _x, float _y, float _z);

#endif
