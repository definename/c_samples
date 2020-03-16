#include "test_util.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <libgen.h>

#define CWD "/home/olehk/projects/c_samples/c_path"

static char* get_cwd(void) {
    char *cwd = malloc(PATH_MAX);
    if (cwd) {
        if (getcwd(cwd, PATH_MAX)) {
            log_debug("Cwd:%s\n", cwd);
            return cwd;
        }
    }
}

int main (int argc, const char * argv[]) {
    const char *dir_name = "filename";

    char *name_copy = malloc(PATH_MAX);
    strcpy(name_copy, dir_name);
    log_debug("Name copy:%s\n", name_copy);

    char* bname = basename(name_copy);
    if (strcmp(bname, "..") == 0 || strcmp(bname, ".") == 0 || strcmp(bname, "/") == 0) {
        log_debug("NOK base name:%s\n", bname);
    } else {
        log_debug("OK base name:%s\n", bname);

        char* dir_copy = malloc(PATH_MAX);
        strcpy(dir_copy, dir_name);
        log_debug("Dir copy:%s\n", dir_copy);
        char *dname = dirname(dir_copy);
        log_debug("Dir name:%s\n", dname);

        char *cwd = malloc(PATH_MAX);
        if (cwd) {
            strcpy(cwd, CWD);
            strcat(cwd, "/");
            strcat(cwd, dname);
            log_debug("Resolve:%s\n", cwd);
            char *resolved = realpath(cwd, NULL);
            if (resolved) {
                log_debug("Resolved:%s\n", resolved);

                size_t s = strlen(CWD);
                log_debug("Size:%zu\n", s);
                if (strncmp(CWD, resolved , s) == 0) {
                    log_debug("Name OK\n");
                } else {
                    log_debug("Name NOK\n");
                }

                free(resolved);
                resolved = NULL;
            } else {
                log_debug("Failed to resolve\n");
            }
            free(cwd);
            cwd = NULL;
        } else {
            log_debug("Failed to alloc cwd");
        }

        free(dir_copy);
        dir_copy = NULL;
    }

    free(name_copy);
    name_copy = NULL;
    return 0;
}