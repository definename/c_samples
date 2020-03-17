#include "test_util.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <libgen.h>

#define CWD "/root/xxx/yyy/zzz"

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
            char *to_reverse = NULL;
            if (to_reverse = malloc(PATH_MAX)) {
                if (*path == '/') {
                    strcpy(to_reverse, "/");
                } else {
                    strcpy(to_reverse, "");
                }

                char* p = NULL;
                int skip = 0;
                do {
                    if (p = strrchr(tmp, '/')) {
                        char *cur = p + 1;
                        if (strcmp(cur, ".") != 0 && strcmp(cur, "") != 0) {
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
                    if (*path == '/') {
                        strcpy(reverse, "/");
                    } else {
                        strcpy(reverse, "");
                    }

                    log_debug("To reverse:%s\n", to_reverse);
                    p = NULL;
                    do {
                        if (p = strrchr(to_reverse, '/')) {
                            char *cur = p + 1;
                            if (strcmp(cur, "") != 0) {
                                strcat(reverse, cur);
                                strcat(reverse, "/");
                            }
                            *p = '\0';
                        }
                    } while(p);

                    if (to_reverse && strcmp(to_reverse, "") != 0) {
                        strcat(reverse, to_reverse);
                        strcat(to_reverse, "/");
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

int main (int argc, const char * argv[]) {
    char* test1 = malloc(PATH_MAX);
    const char *test1_res = "/root/xxx/dir1/dir2/dir3/";
// #define CWD "/../../../../../a"
// #define CWD "/a/.."
// #define CWD "/a/./b/../../c/"
// #define CWD "/a/.."
// #define CWD "/home"
    if (test1) {
        strcpy(test1, CWD);
        strcat(test1, "/");
        strcat(test1, "../../dir1/dir2/dir3");

        for (int i = 0; i != 100; ++i) {
            log_debug("Cwd:%s\n", STRSAFE(test1));
            char *test1_res = simplify_path(test1);
            log_debug("Test1 res:%s\n", STRSAFE(test1_res));
            if (strcmp(test1_res, "")) {
                log_debug("TEST1 OK\n");
            } else {
                log_debug("TEST1 NOK");
            }
            free(test1_res);
            test1_res = NULL;
        }

        free(test1);
        test1 = NULL;
    } else {
        log_debug("Failed to alloc test\n");
    }
    return 0;
}