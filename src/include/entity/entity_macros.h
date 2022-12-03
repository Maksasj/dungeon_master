#ifndef _ENTITY_MACROS_H_
#define _ENTITY_MACROS_H_

#include "entity.h"

#include "../prototypes/skeleton.h"

#define _SKELETON_NINJA_ENTITY_(X, Y)                       \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(1, 1, 1, 1, 1),                               \
        24)))))                                             \

#define _SKELETON_KING_ENTITY_(X, Y)                        \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(1, 1, 1, 1, 1),                               \
        48)))))                                             \

#define _SKELETON_ANCIENT_ENTITY_(X, Y)                     \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(1, 1, 1, 1, 1),                               \
        72)))))                                             \

#define _NECROMANCER_ENTITY_(X, Y)                          \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(1, 1, 1, 1, 1),                               \
        96)))))                                             \

#endif
