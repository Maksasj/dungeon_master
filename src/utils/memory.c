#include "../../include/utils/memory.h"

vu16* charBlock(u32 _block) {
    return (vu16*) (_TILEMAP_ + (_block * _CHAR_BLOCK_SIZE_));
}

vu16* screenBlock(u32 _block) {
    return (vu16*) (_TILEMAP_ + (_block * _SCREEN_BLOCK_SIZE_));
}

void setScreenBlock(vu16* _block, u16 _value) {
    i32 i; i32 j;
    for(i = 0; i < 30; ++i) {
        for(j = 0; j < 20; ++j) {
            _block[i + j * 32] = _value;
        }
    }
}

void memcpy16DMA(u16* _dest, u16* _source, i32 _amount) {
    *_DMA_3_SOURCE_ = (u32) _source;
    *_DMA_3_DESTINATION_ = (u32) _dest;
    *_DMA_3_CONTROL_ = _amount | _DMA_16_ | _DMA_ENABLE_;
}
