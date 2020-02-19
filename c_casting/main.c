#include <inttypes.h>
#include "test_util.h"

int main (int argc, const char * argv[]) {
    log_debug("%zu\n", sizeof(int32_t));
    int32_t a = INT32_MAX;
    log_debug("%"PRId32"\n", a);
    // a has to be explicitly casted to uint64_t;
    uint64_t b = (uint64_t)a * 1000;
    log_debug("%"PRIu64"\n", b);

    return 0;
}
