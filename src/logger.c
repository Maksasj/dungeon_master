#include "include/logger.h"

inline void log(LOG_LEVEL lvl, const char* fmt, ...) {
    _REG_LOG_ENABLE_ = 0xC0DE;
    _REG_LOG_LEVEL_ = lvl;

    va_list args;
    va_start(args, fmt);

    char* const log = (char*) 0x4FFF600;
    vsnprintf(log, 0x100, fmt, args);

    va_end(args);
}
