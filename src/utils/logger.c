#include "../../include/utils/logger.h"

inline void log(LogLevel _lvl, const i8* _fmt, ...) {
    _REG_LOG_ENABLE_ = 0xC0DE;
    _REG_LogLevel_ = _lvl;

    va_list args;
    va_start(args, _fmt);

    i8* const log = (i8*) 0x4FFF600;
    vsnprintf(log, 0x100, _fmt, args);

    va_end(args);
}
