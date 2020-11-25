#include <stdio.h>
#include <string.h>

#define FGETS_READ_LEN 10

static void test_fgets(void) {
    char words[FGETS_READ_LEN];
    memset(words, 0, sizeof(words));
    while (fgets(words, FGETS_READ_LEN, stdin) != NULL && words[0] != '\n') {
        fputs("-", stdout);
        fputs(words, stdout);
    }
}

#define FILE_PATH "./some/path/do_it"

int main (int argc, const char *argv[]) {
    FILE* fp = fopen(FILE_PATH, "w");
    if (fp == NULL) {
        printf("Failed to open file\n");
        fclose(fp);
    }
    // test_fgets();
    return 0;
}
