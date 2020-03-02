#include "test_struct_compound_literal.h"
#include "test_util.h"

struct rect {
    double x;
    double y;
};

static double rect_area(struct rect r) {
    return r.x * r.y;
}

static double rect_areap(struct rect *r) {
    return r->x * r->y;
}

void test_struct_compound_literal(void) {
    struct rect r = {0};
    r = (struct rect) { 2.0, 4.0};
    double area = rect_area(r);
    log_debug("rect area:%.02f\n", area);

    double areap = rect_areap(&(struct rect) { 4.0, 3.0});
    log_debug("rect areap:%.02f\n", areap);
}