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

/* pointer to the DMA count/control */
#define _DMA_COUNT_ ((vu32*) 0x40000DC)

void memcpy16DMA(u16* _dest, u16* _source, i32 _amount);

#endif
