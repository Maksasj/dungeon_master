#ifndef _ENTITY_MACROS_H_
#define _ENTITY_MACROS_H_

#include "entity.h"

#include "../prototypes/skeleton.h"

#define _SKELETON_NINJA_ENTITY_(X, Y)                       \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
    addDodgeCallback(&skeleton_try_dodge,                   \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(1, 3, 0, 0, 0),                               \
        24))))))                                            \

#define _SKELETON_KING_ENTITY_(X, Y)                        \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
    addDodgeCallback(&skeleton_try_dodge,                   \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(3, 1, 0, 1, 0),                               \
        48))))))                                            \

#define _SKELETON_ANCIENT_ENTITY_(X, Y)                     \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
    addDodgeCallback(&skeleton_try_dodge,                   \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(1, 0, 0, 1, 0),                               \
        72))))))                                            \

#define _NECROMANCER_ENTITY_(X, Y)                          \
    addUpdate_CallBack(&skeleton_update,                    \
    addOnCollisionEnter_CallBack(&checkCollision,           \
    addDie_CallBack(&skeleton_kill,                         \
    addAttack_CallBack(&skeletonCalculateDamage,            \
    addDodgeCallback(&skeleton_try_dodge,                   \
                                                            \
    entityInit(                                             \
        newFVec2(X, Y),                                     \
        stats(2, 2, 1, 0, 0),                               \
        96))))))                                            \

#endif
