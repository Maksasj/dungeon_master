/**
 * Statblock
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * File that cotains defenition for all structures and functions needed to work with stats
*/

#ifndef _STATBLOCK_H_
#define _STATBLOCK_H_

#include "../utils/types.h"

/* Defenition of the stattype */
typedef i32 stattype;

/* Constant attack cooldown */
#define _DEFAULT_ATTACK_COOLDOWN_ 70

/* Constant mana modifier */
#define _MANA_MODIFIER_FROM_INTELLECT_ 10

/* Constant attack cooldown modifier from agility stat */
#define _ATTACK_COOLDOWN_MODIFIER_FROM_AGILITY_ 10

/* Constant relation between dodge chance and agility stat */
#define _DODGE_CHANCE_FROM_AGILITY_ 10

/* Structure that contains all possible stats */
typedef struct Statblock {
    /* Basically health stat */
    stattype stamina;
    
    /* Basically dodge chace and attack speed stat */
    stattype agility;

    /* Basically mana damage and mana pool stat */
    stattype intellect;

    /* Basically physically damage stat */
    stattype strength;

    /* Armor stat */
    stattype armor;
} Statblock;

/**
 * Initializes stat block instance
 * 
 * @param _stamina Stamina stat
 * @param _agility Agility stat
 * @param _intellect Intellect stat
 * @param _strength Strength stat
 * @param _armor Armor stat
 * @return Instance of the new stat block
*/
Statblock statsInit(stattype _stamina, stattype _agility, stattype _intellect, stattype _strength, stattype _armor);

#endif
