#include "test_util.h"
#include "internal_linkage.h"

extern int external_linkage_var;

int main (int argc, const char * argv[]) {
    log_debug("External linkage var:%d\n", external_linkage_var);
    log_debug("Internal linkage var:%d\n", get_var());
    return 0;
}