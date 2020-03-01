#include "test_anonymous_struct.h"
#include "test_util.h"

struct person {
    int id;
    struct {char first[20]; char last[20];};
};

void test_anonymous_struct(void) {
    struct person p = {1, {"Ivan", "Durak"}};
    log_debug("f:%s l:%s\n", p.first, p.last);
}