#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

#include <glib.h>
#include <gio/gio.h>

#include "mygenerated.h"

#define BUS_NAME "com.myname"
#define OBJECT_PATH "/com/myname/obj"

static GMainLoop *loop = NULL;

#define log_debug(format, ...) g_print(format, ##__VA_ARGS__)

void signal_handler(int sig) {
    if(g_main_loop_is_running(loop)) {
        log_debug("Exit requested:%d...\n", sig);
        g_main_loop_quit(loop);
    }
}

static gboolean on_handle_mymethod(MYNAMESPACEGen *interface,
                                   GDBusMethodInvocation *invocation,
                                   const gchar *greeting,
                                   gpointer user_data)
{
    log_debug("on_handle_mymethod:%s\n", greeting);

    gchar *response = g_strdup_printf("Hello %s!", greeting);
    mynamespace_gen_complete_mymethod(interface, invocation, response);
    g_free (response);
    return TRUE;
}

void on_bus_acquired(GDBusConnection *connection,
                     const gchar *name,
                     gpointer user_data) {
    log_debug("on_bus_acquired:%s\n", name);

    MYNAMESPACEGen* interface = mynamespace_gen_skeleton_new();
    guint ret = g_signal_connect(interface,
                                 "handle_mymethod",
                                 G_CALLBACK(on_handle_mymethod),
                                 NULL);

    if (ret > 0) {
        log_debug("Callback successfully connected to a signal\n");

        GError *error = NULL;
        gboolean code = g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(interface),
                                                         connection,
                                                         OBJECT_PATH,
                                                         &error);
        if (code == true) {
            log_debug("Interface has been successfully exported\n");
        } else {
            log_debug("Failed to export interface:%s\n", error->message);
        }
    } else {
        log_debug("Failed to connect callback to a signal\n");
    }
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
                                  BUS_NAME,
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
