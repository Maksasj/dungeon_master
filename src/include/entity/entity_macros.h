#ifndef _ENTITY_MACROS_H_
#define _ENTITY_MACROS_H_

#include "entity.h"

#include "../prototypes/skeleton_ninja.h"
#include "../prototypes/skeleton_king.h"
#include "../prototypes/skeleton_ancient.h"
#include "../prototypes/necromancer.h"

#define _SKELETON_NINJA_ENTITY_(X, Y)                           \
    addUpdate_CallBack(&skeletonNinjaUpdate,                    \
    addOnCollisionEnter_CallBack(&checkCollision,               \
    addDie_CallBack(&skeletonNinjaKill,                         \
    addAttack_CallBack(&skeletonNinjaCalculateDamage,           \
                                                                \
    entityInit(                                                 \
        newFVec2(X, Y),                                         \
        stats(1, 1, 1, 1, 1),                                   \
        24)))))                                                 \

#define _SKELETON_KING_ENTITY_(X, Y)                            \
    addUpdate_CallBack(&skeletonKingUpdate,                     \
    addOnCollisionEnter_CallBack(&checkCollision,               \
    addDie_CallBack(&skeletonKingKill,                          \
    addAttack_CallBack(&skeletonKingCalculateDamage,            \
                                                                \
    entityInit(                                                 \
        newFVec2(X, Y),                                         \
        stats(1, 1, 1, 1, 1),                                   \
        48)))))                                                 \

#define _SKELETON_ANCIENT_ENTITY_(X, Y)                         \
    addUpdate_CallBack(&skeletonAncientUpdate,                  \
    addOnCollisionEnter_CallBack(&checkCollision,               \
    addDie_CallBack(&skeletonAncientKill,                       \
    addAttack_CallBack(&skeletonAncientCalculateDamage,         \
                                                                \
    entityInit(                                                 \
        newFVec2(X, Y),                                         \
        stats(1, 1, 1, 1, 1),                                   \
        72)))))                                                 \

#define _NECROMANCER_ENTITY_(X, Y)                              \
    addUpdate_CallBack(&necromancerUpdate,                      \
    addOnCollisionEnter_CallBack(&checkCollision,               \
    addDie_CallBack(&necromancerKill,                           \
    addAttack_CallBack(&necromancerCalculateDamage,             \
                                                                \
    entityInit(                                                 \
        newFVec2(X, Y),                                         \
        stats(1, 1, 1, 1, 1),                                   \
        96)))))                                                 \

#endif
