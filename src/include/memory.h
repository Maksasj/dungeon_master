#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "types.h"

/* flag for turning on DMA */
#define _DMA_ENABLE_ 0x80000000

/* flags for the sizes to transfer, 16 or 32 bits */
#define _DMA_16_ 0x00000000
#define _DMA_32_ 0x04000000

#define _DMA_SOURCE_ ((vu32*) 0x40000D4)

/* pointer to the DMA destination location */
#define _DMA_DESTINATION_ ((vu32*) 0x40000D8)

/* this causes the DMA destination to be the same each time rather than increment */
#define _DMA_DESTINATION_FIXED_ 0x400000

/* pointers to the DMA source/dest locations and control registers */
#define _DMA_1_SOURCE_      ((vu32*) 0x40000BC)
#define _DMA_1_DESTINATION_ ((vu32*) 0x40000C0)
#define _DMA_1_CONTROL_     ((vu32*) 0x40000C4)

#define _DMA_2_SOURCE_      ((vu32*) 0x40000C8)
#define _DMA_2_DESTINATION_ ((vu32*) 0x40000CC)
#define _DMA_2_CONTROL_     ((vu32*) 0x40000D0)

#define _DMA_3_SOURCE_      ((vu32*) 0x40000D4)
#define _DMA_3_DESTINATION_ ((vu32*) 0x40000D8)
#define _DMA_3_CONTROL_     ((vu32*) 0x40000DC)

/* this causes the DMA to repeat the transfer automatically on some interval */
#define _DMA_REPEAT_ 0x2000000

/* this causes the DMA repeat interval to be synced with timer 0 */
#define _DMA_SYNC_TO_TIMER_ 0x30000000

/* pointer to the DMA count/control */
#define _DMA_COUNT_ ((vu32*) 0x40000DC)

void memcpy16DMA(u16* _dest, u16* _source, i32 _amount);

#endif
