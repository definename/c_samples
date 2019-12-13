#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_NAME "TEST_STR_NAME"

void test_str_heap_copy(const char * const name);
void test_str_heap_copy1(const char * const name);
void test_strdup();

int main (int argc, const char * argv[]) {
    test_str_heap_copy(TEST_NAME);
    test_str_heap_copy1(TEST_NAME);
    test_strdup(TEST_NAME);
    test_strdup(NULL);
    return 0;
}

void test_str_heap_copy(const char * const name) {
    char* name_copy = strdup(name);
    printf("%s\n", name_copy);
    free(name_copy);
}

void test_str_heap_copy1(const char * const name) {
    size_t size = strlen(name) + 1;
    char* name_copy = malloc(size * sizeof(char));
    strcpy(name_copy, name);
    printf("%s\n", name_copy);
    free(name_copy);
}

void test_strdup(char* test_str) {
    if (test_str) {
        char* test_str_dup = strdup(test_str);
        if (test_str_dup) {
            printf("Test str dup is ok:%p\n", test_str_dup);
            free(test_str_dup);
        } else {
            printf("Test str dup is nok\n");
        }
    } else {
        printf("Test str:%p is null\n", test_str);
    }
}