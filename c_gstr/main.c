#include <glib/gprintf.h>

#define log_debug(format, ...) g_printf(format, ##__VA_ARGS__)
#define NAME_DST_SIZE 10
#define TEST_NAME "testname11111111111"

typedef struct {
    gchar name[NAME_DST_SIZE];
} type_t;

int main (int argc, const char * argv[]) {
    type_t* test_type = g_try_malloc0(sizeof(type_t));
    if (test_type != NULL) {
        gsize ret = g_strlcpy(test_type->name, TEST_NAME, NAME_DST_SIZE);
        log_debug("Source size returned:%lu\n", ret);
        if (ret >= NAME_DST_SIZE) {
            log_debug("Destination is to short truncation occured:%s\n", test_type->name);
        } else {
            log_debug("%s\n", test_type->name);
        }
        g_free(test_type);
    }
    return 0;
}
