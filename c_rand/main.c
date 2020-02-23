#include "test_util.h"
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

int main (int argc, const char * argv[]) {
    // time_t seed = 1;
    time_t seed = time(NULL);
    log_debug("seed:%u\n", (unsigned int)seed);
    srand((unsigned int)seed);
    for (int i = 0; i < 10; ++i) {
        int r = rand();
        log_debug("rand:%d\n", r % 10);
    }
    return 0;
}