#ifndef _TEST_ROM_H_
#define _TEST_ROM_H_

#include "../include/utils/logger.h"
#include "../include/buttons.h"

#define _WAIT_TEST_START_ while(!buttonPressed(_BUTTON_START_)){}
#define _WAIT_TEST_END_ {while(1){}};

#define ensure(condition)                                           \
    if(!(condition)) {                                              \
        log(LOG_ERR, "Error in: "__FILE__);                                     \
    } else                                                          \

#endif
