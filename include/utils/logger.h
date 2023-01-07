/**
 * logger
 *
 * @authors
 * Maksimas Jaroslavcevas, Oskaras Vištorskis
 *
 * @brief
 * Printf analogue (mGBA emulator)
*/

#ifndef _LOGGER_
#define _LOGGER_

#include <stdarg.h>
#include <stdio.h>

#include "types.h"

// Enum to store Log Level
typedef enum LogLevel {
    LOG_FATAL                   = 0x100,
    LOG_ERR                     = 0x101,
    LOG_WARN                    = 0x102,
    LOG_INFO                    = 0x103
} LogLevel;

// Register for turning on logs
#define _REG_LOG_ENABLE_          *(vu16*) 0x4FFF780
// Register for turning on needed LogLevel
#define _REG_LogLevel_           *(vu16*) 0x4FFF700

/**
 * Printf analogue (mGBA emulator)
 * 
 * @param _lvl    Log level
 * @param _fmt    Text format
 * @param ...     Additional arguments
*/
inline void log(LogLevel _lvl, const char* _fmt, ...);

#endif
