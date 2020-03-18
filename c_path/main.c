#include "test_util.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <libgen.h>

static char* get_cwd(void) {
    char *cwd = malloc(PATH_MAX);
    if (cwd) {
        if (getcwd(cwd, PATH_MAX)) {
            log_debug("Cwd:%s\n", cwd);
            return cwd;
        }
    }
}

static char* simplify_path(const char* const path) {
    char *reverse = NULL;
    char *tmp = NULL;
    if (tmp = strdup(path)) {
        char *dir = NULL;
        if (dir = malloc(PATH_MAX)) {
            memset(dir, 0, PATH_MAX);
            char *to_reverse = NULL;
            if (to_reverse = malloc(PATH_MAX)) {
                memset(to_reverse, 0, PATH_MAX);
                if (*path == '/') {
                    strcpy(to_reverse, "/");
                } else {
                    strcpy(to_reverse, "");
                }

                char* p = NULL;
                int skip = 0;
                do {
                    if (p = strrchr(tmp, '/')) {
                        if (strcmp(p, "/.") != 0 && strcmp(p, "/") != 0) {
                            const char * const cur = p + 1;
                            if (strcmp(cur, "..") == 0) {
                                skip++;
                            } else if (skip != 0) {
                                --skip;
                            } else if (strcmp(dir, "") == 0) {
                                strcpy(dir, cur);
                            } else {
                                strcat(to_reverse, dir);
                                strcat(to_reverse, "/");
                                *dir = '\0';
                                strcpy(dir, cur);
                            }
                        }
                        *p = '\0';
                    }
                } while(p);

                if (dir && strcmp(dir, "") != 0) {
                    strcat(to_reverse, dir);
                    strcat(to_reverse, "/");
                }

                if (skip == 0 && tmp && strcmp(tmp, "") != 0) {
                    strcat(to_reverse, tmp);
                    strcat(to_reverse, "/");
                }

                if (reverse = malloc(PATH_MAX)) {
                    memset(reverse, 0, PATH_MAX);
                    if (*path == '/') {
                        strcpy(reverse, "/");
                    } else {
                        strcpy(reverse, "");
                    }

                    log_debug("To reverse:%s\n", to_reverse);
                    p = NULL;
                    do {
                        if (p = strrchr(to_reverse, '/')) {
                            if (strcmp(p, "/") != 0) {
                                strcat(reverse, p + 1);
                                strcat(reverse, "/");
                            }
                            *p = '\0';
                        }
                    } while(p);

                    if (to_reverse && strcmp(to_reverse, "") != 0) {
                        strcat(reverse, to_reverse);
                        strcat(reverse, "/");
                    }
                } else {
                    log_debug("Failed to alloc reverse string\n");
                }
                free(to_reverse);
                to_reverse = NULL;
            } else {
                log_debug("Failed to alloc to reverse string\n");
            }
            free(dir);
            dir = NULL;
        } else {
            log_debug("Failed to alloc tmp string\n");
        }
        free(tmp);
        tmp = NULL;
    } else {
        log_debug("Failed to duplicate tmp string\n");
    }
    return reverse;
}

bool test(const char* const test_path, const char* const test_expected) {
    log_debug("TEST PATH:%s\n", STRSAFE(test_path));
    char *test_result = simplify_path(test_path);
    log_debug("SIMPLIFY:%s EXPECTED:%s\n", STRSAFE(test_result), STRSAFE(test_expected));

    bool res = false;
    if (strcmp(test_result, test_expected) == 0) {
        log_debug("TEST1 OK\n");
        res = true;
    } else {
        log_debug("TEST1 NOK\n");
        res = false;
    }

    free(test_result);
    test_result = NULL;
    return res;
}

typedef struct {
    const char* test_path;
    const char* test_expected;
} test_t;

#define CWD_ROOT "/root/xxx/yyy/zzz"
#define CWD_NO_ROOT "root/xxx/yyy/zzz"

static test_t test_stack[] = {
    { CWD_ROOT "/../../dir1/dir2/dir3", "/root/xxx/dir1/dir2/dir3/" },
    { CWD_NO_ROOT "/../../dir1/dir2/dir3", "root/xxx/dir1/dir2/dir3/" },
    { "/root/../dir1", "/dir1/" },
    { CWD_ROOT, "/root/xxx/yyy/zzz/" },
    { CWD_NO_ROOT, "root/xxx/yyy/zzz/" },
    { CWD_ROOT "/../../../../", "/" },
    { CWD_NO_ROOT "/../../../../", "" },
};

const size_t test_stack_size = COUNT_OF(test_stack);

int main (int argc, const char * argv[]) {
    for (size_t i = 0; i < test_stack_size; ++i) {
        unsigned int count = 1;
        bool test_result = true;
        while (count != 0 && test_result) {
            test_t t = test_stack[i];
            test_result = test(t.test_path, t.test_expected);
            --count;
        }
        if (!test_result) {
            break;
        }
    }
    // #define CWD "/../../../../../a"
    // #define CWD "/a/.."
    // #define CWD "/a/./b/../../c/"
    // #define CWD "/a/.."
    // #define CWD "/home"
    return 0;
}