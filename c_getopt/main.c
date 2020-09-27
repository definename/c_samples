#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

typedef enum {
    START = 1,
    STOP,
    HELP,
    ACTION_LAST,
} action_t;

static struct option long_options[] = {
    {"start", optional_argument, NULL, START},
    {"stop", no_argument, NULL, STOP},
    {"help", no_argument, NULL, HELP},
    {0, 0, 0, 0},
};

#define USAGE_STR \
    "Usage:\n" \
    "--start[=](param) - start something\n" \
    "--stop            - stop something\n" \
    "--help            - show this help \n" \

int main (int argc, char * const argv[]) {
    while (true) {
        int ret = getopt_long(argc, argv, "", long_options, NULL);
        if (ret == -1) {
            break;
        } else if (ret == '?') {
            continue;
        } else if (ret == START) {
            if (optarg) {
                log_debug("start in progress with args:%s\n", optarg);
            } else {
                log_debug("start in progres\n");
            }
        } else if (ret == STOP) {
            log_debug("stop in progress\n");
        } else if (ret == HELP) {
            log_debug("%s", USAGE_STR);
        }
    }
    return 0;
}
