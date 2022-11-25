#include "include/logger.h"

inline void log(LogLevel _lvl, const char* _fmt, ...) {
    _REG_LOG_ENABLE_ = 0xC0DE;
    _REG_LogLevel_ = _lvl;

    va_list args;
    va_start(args, _fmt);

    char* const log = (char*) 0x4FFF600;
    vsnprintf(log, 0x100, _fmt, args);

    va_end(args);
}
