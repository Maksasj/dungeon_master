/**
 * Memory
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Allows to manipulate with GBA memory
*/

#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "types.h"

/* Bit for turning on Direct Memory Access (DMA) */
#define _DMA_ENABLE_ 0x80000000

/* Chunk Size. Sets DMA to copy by halfword (if clear) or word (if set) */
#define _DMA_16_ 0x00000000
#define _DMA_32_ 0x04000000

/* This causes the DMA destination to be the same each time rather than increment */
#define _DMA_DESTINATION_FIXED_ 0x400000

/* Direct Memory Access 1 */
#define _DMA_1_SOURCE_      ((vu32*) 0x40000BC)
#define _DMA_1_DESTINATION_ ((vu32*) 0x40000C0)
#define _DMA_1_CONTROL_     ((vu32*) 0x40000C4)

/* Direct Memory Access 2 */
#define _DMA_2_SOURCE_      ((vu32*) 0x40000C8)
#define _DMA_2_DESTINATION_ ((vu32*) 0x40000CC)
#define _DMA_2_CONTROL_     ((vu32*) 0x40000D0)

/* Direct Memory Access 3 */
#define _DMA_3_SOURCE_      ((vu32*) 0x40000D4)
#define _DMA_3_DESTINATION_ ((vu32*) 0x40000D8)
#define _DMA_3_CONTROL_     ((vu32*) 0x40000DC)

/* Repeats the copy at each VBlank or HBlank if the DMA timing has been set to those modes. */
#define _DMA_REPEAT_ 0x2000000

/* This causes the DMA repeat interval to be synced with timer 0 */
#define _DMA_SYNC_TO_TIMER_ 0x30000000

/* Constant what determines tile map thing */
#define _TILEMAP_               0x6000000

/* Size of the char memory block */
#define _CHAR_BLOCK_SIZE_       0x4000

/* Size of the screen memory block */
#define _SCREEN_BLOCK_SIZE_     0x800

/**
 * Returns location of block as char block pointer
 * 
 * @param   _block  Index of the block
 * @return          Pointer to char block
*/
vu16* charBlock(u32 _block);

/**
 * Returns location of block as screen block pointer
 * 
 * @param   _block  Index of the block
 * @return          Pointer to screen block
*/
vu16* screenBlock(u32 _block);


/**
 * Sets specific value for all VISIBLE tiles in specific screen block
 * 
 * @param   _block  Pointer to the target screen block
 * @param   _value  Value for all tiles in provided screen block
*/
void setScreenBlock(vu16* _block, u16 _value);

/**
 * Copy for halfwords
 * 
 * @param _dest      Destination address.
 * @param _source    Source address.
 * @param _amount    Number of halfwords to fill.
*/
void memcpy16DMA(u16* _dest, u16* _source, i32 _amount);

#endif
