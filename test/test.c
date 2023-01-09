#include "test.h"

int main() {
    _WAIT_TEST_START_
    log(LOG_INFO, "Test started");

    log(LOG_INFO, "Test ended");
    _WAIT_TEST_END_
    return 0;
}
