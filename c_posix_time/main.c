#include <math.h>
#include <time.h>
#include <inttypes.h>
#include "test_util.h"

void get_timestamp_milisec1(void);
void get_timestamp_milisec2(void);

int main (int argc, const char * argv[]) {
    get_timestamp_milisec1();
    get_timestamp_milisec2();
    return 0;
}

void get_timestamp_milisec1(void) {
    long ms = 0;
    time_t s = 0;
    struct timespec ts = {0};
    clock_gettime(CLOCK_REALTIME, &ts);

    s  = ts.tv_sec;
    ms = round(ts.tv_nsec / 1.0e6);
    if (ms > 999) {
        s++;
        ms = 0;
    }

    // Retrieve expected size.
    const int sz = snprintf(NULL, 0, "%010ld%03ld", s, ms);
    log_debug("Expected timestamp size:%d\n", sz);

    // Build string representation of timestamp.
    char input_str[sz + 1];
    sprintf(input_str, "%010ld%03ld", s, ms);
    log_debug("Input str:%s\n", input_str);

    // Convert string to uint64_t.
    uint64_t milisec = 0;
    sscanf(input_str, "%"PRIu64, &milisec);
    log_debug("milisec:%"PRIu64"\n", milisec);
}

void get_timestamp_milisec2(void) {
    struct timespec ts = {0};
    clock_gettime(CLOCK_REALTIME, &ts);
    uint64_t sec = ts.tv_sec;
    log_debug("sec:%"PRIu64"\n", sec);
    sec *= 1000;
    uint64_t nsec = ts.tv_nsec;
    log_debug("nsec:%"PRIu64"\n", nsec);
    nsec /= 1000000;
    uint64_t milisec = sec + nsec;
    log_debug("milisec:%"PRIu64"\n", milisec);
}