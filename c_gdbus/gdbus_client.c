#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

#include <glib.h>
#include <gio/gio.h>

#include "mygenerated.h"

#define BUS_NAME "com.myname"
#define OBJECT_PATH "/com/myname/obj"

#define log_debug(format, ...) g_print(format, ##__VA_ARGS__)

int main (int argc, const char * argv[]) {
	MYNAMESPACEGen *proxy;
	GError *error = NULL;
	proxy = mynamespace_gen_proxy_new_for_bus_sync(G_BUS_TYPE_SESSION,
													 G_DBUS_PROXY_FLAGS_NONE,
													 BUS_NAME,
													 OBJECT_PATH,
													 NULL,
													 &error);

	gchar **buf;
	mynamespace_gen_call_mymethod_sync(proxy, "my Lord", buf, NULL, &error);
	log_debug("Response:%s\n", *buf);

	g_object_unref(proxy);
	return 0;
}
