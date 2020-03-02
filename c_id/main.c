#include "test_util.h"
#include <inttypes.h>

int main (int argc, const char * argv[]) {
    uint64_t z = UINT32_MAX;
    log_debug("%"PRIu64"\n", ++z & UINT32_MAX);
    log_debug("%"PRIu64"\n", z++ & UINT32_MAX);
    log_debug("%"PRIu64"\n", z & UINT32_MAX);
    return 0;
}