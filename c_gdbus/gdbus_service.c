#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

#include <glib.h>
#include <gio/gio.h>

static GMainLoop *loop = NULL;

#define log_debug(format, ...) g_print(format, ##__VA_ARGS__)

void signal_handler(int sig) {
    if(g_main_loop_is_running(loop)) {
        log_debug("Exit requested:%d...\n", sig);
        g_main_loop_quit(loop);
    }
}

void on_bus_acquired(GDBusConnection *connection,
                     const gchar *name,
                     gpointer user_data) {
    log_debug("on_bus_acquired:%s\n", name);
}

void on_bus_name_acquired(GDBusConnection *connection,
                          const gchar *name,
                          gpointer user_data) {
    log_debug("on_bus_name_acquired:%s\n", name);
}

void on_bus_name_lost(GDBusConnection *connection,
                      const gchar *name,
                      gpointer user_data) {
    log_debug("on_bus_name_lost:%s\n", name);
}

int main (int argc, const char * argv[]) {
    loop = g_main_loop_new(NULL, false);

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    guint own_id = g_bus_own_name(G_BUS_TYPE_SESSION,
                                  "com.fatminmin",
                                  G_BUS_NAME_OWNER_FLAGS_NONE,
                                  on_bus_acquired,
                                  on_bus_name_acquired,
                                  on_bus_name_lost,
                                  NULL,
                                  NULL);

    log_debug("Waiting for termination request...\n");
    g_main_loop_run(loop);

    g_bus_unown_name(own_id);
    g_main_loop_unref(loop);
    return 0;
}
