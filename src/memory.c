#include "include/memory.h"

void memcpy16DMA(u16* _dest, u16* _source, i32 _amount) {
    *_DMA_3_SOURCE_ = (u32) _source;
    *_DMA_3_DESTINATION_ = (u32) _dest;
    *_DMA_3_CONTROL_ = _amount | _DMA_16_ | _DMA_ENABLE_;
}
