/**
 * interruption
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows to manipulate with GBA interruptions
*/

#ifndef _INTERRUPTION_H_
#define _INTERRUPTION_H_

#include "../utils/types.h"

// Interrupt Master Enable Register
#define _INTERRUPT_ENABLE_ ((u16*) 0x4000208)

// Interrupt Enable Register
#define _INTERRUPT_SELECTION_ ((u16*) 0x4000200)

// Interrupt Request Flags / IRQ Acknowledge
#define _INTERRUPT_STATE_ ((u16*) 0x4000202)

// Pointer to user IRQ handler (32bit ARM code)
#define _INTERRUPT_CALLBACK_ ((u32*) 0x3007FFC)

// This register controls the LCD interrupts.
#define _DISPLAY_INTERRUPTS_ ((u16*) 0x4000004)

// Interruption bites
#define _INT_VBLANK_    0x0001

/**
 * Initialize interruption
 * 
 * @param   _ptr   interruption
*/
void interruptionInit(void (*_ptr)());

#endif
