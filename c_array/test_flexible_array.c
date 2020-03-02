#include "test_flexible_array.h"
#include "test_util.h"
#include "stdlib.h"

struct flex {
    int count;
    double scores[];
};

void test_flexible_array(void) {
    struct flex *pf = NULL;
    int n = 3;
    pf = malloc(sizeof(struct flex) + n * sizeof(double));
    pf->count = n;
    for (int i = 0; i < pf->count; ++i) {
        pf->scores[i] = i * 2.0;
    }
    for (int i = 0; i < pf->count; ++i) {
        log_debug("%.03f\n", pf->scores[i]);
    }
    free(pf);
}