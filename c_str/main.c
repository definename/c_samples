#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_NAME "TEST_STR_NAME"

void test_str_fn(const char * const name);

int main (int argc, const char * argv[]) {
    // ........................................
    char* test_str = NULL;
    if (test_str) {
        char* test_str_dup = strdup(test_str);
        if (test_str_dup) {
            printf("Test str dup is ok\n");
        } else {
            printf("Test str dup is nok\n");
        }
    } else {
        printf("Test str is null\n");
    }
    // ........................................
    test_str_fn(TEST_NAME);
    return 0;
}

void test_str_fn(const char * const name) {
    char* name_copy = strdup(name);
    printf("%s\n", name_copy);
    free(name_copy);
}
