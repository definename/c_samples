#include "test_util.h"

enum data_t {
    INTEGER = 0,
    DOUBLE
};

union data {
    int data_int;
    double data_double;
};

struct container_t {
    enum data_t cmd_case;
    union data info;
};

int main (int argc, const char *argv[]) {
    log_debug("It works\n");

    struct container_t c1 = {0};
    c1.cmd_case = INTEGER;
    c1.info.data_int = 1;

    struct container_t c2 = {0};
    c2.cmd_case = DOUBLE;
    c2.info.data_double = 2.0;

    const struct container_t arr[2] = { c1, c2 };
    for (size_t i = 0; i < COUNT_OF(arr); ++i) {
        const struct container_t *v = &arr[i];
        if (v->cmd_case == INTEGER) {
            log_debug("Int:%d\n", v->info.data_int);
        } else if (v->cmd_case == DOUBLE) {
            log_debug("Double:%f\n", v->info.data_double);
        } else {
            log_debug("Unknown type was given\n");
        }
    }
    return 0;
}