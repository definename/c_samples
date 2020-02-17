#include "test_fgets.h"
#include "test_util.h"
#include <string.h>

#define FGETS_READ_LEN 10

void test_fgets(void) {
    char words[FGETS_READ_LEN];
    memset(words, 0, sizeof(words));
    while (fgets(words, FGETS_READ_LEN, stdin) != NULL && words[0] != '\n') {
        fputs("-", stdout);
        fputs(words, stdout);
    }
}