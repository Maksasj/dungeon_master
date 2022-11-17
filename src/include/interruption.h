#ifndef _INTERRUPTION_H_
#define _INTERRUPTION_H_

#include "types.h"

/* the global interrupt enable register */
#define _INTERRUPT_ENABLE_ ((u16*) 0x4000208)

/* this register stores the individual interrupts we want */
#define _INTERRUPT_SELECTION_ ((u16*) 0x4000200)

/* this registers stores which interrupts if any occured */
#define _INTERRUPT_STATE_ ((u16*) 0x4000202)

/* the address of the function to call when an interrupt occurs */
#define _INTERRUPT_CALLBACK_ ((u32*) 0x3007FFC)

/* this register needs a bit set to tell the hardware to send the vblank interrupt */
#define _DISPLAY_INTERRUPTS_ ((u16*) 0x4000004)

/* the interrupts are identified by number, we only care about this one */
#define _INTERRUPT_VBLANK_ 0x1

#endif
