#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

#include <glib.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

static GMainLoop *loop = NULL;

void signal_handler(int sig) {
    if(g_main_loop_is_running(loop)) {
        log_debug("Exit requested:%d...", sig);
        g_main_loop_quit(loop);
    }
}

int main (int argc, const char * argv[]) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    loop = g_main_loop_new(NULL, false);

    log_debug("You are running glib:%d.%d.%d\n", glib_major_version,
                                                 glib_minor_version,
                                                 glib_micro_version);

    log_debug("Waiting for termination request...\n");

    g_main_loop_run(loop);
    return 0;
}
