#include <glib/gprintf.h>

#define log_debug(format, ...) g_printf(format, ##__VA_ARGS__)

typedef struct {
    gint a;
} my_data_t;

void my_func(gpointer list_data, gpointer user_data) {
    my_data_t* l_data = (my_data_t*)list_data;
    gint* u_data = (gint*) user_data;
    log_debug("listdata:%d, userdata:%d\n", l_data->a, *u_data);
}

void my_free(gpointer list_data) {
    my_data_t* data = (my_data_t*)list_data;
    log_debug("listdata free:%d\n", data->a);
    g_free(data);
}

int main (int argc, const char * argv[]) {
    GList* my_list = NULL;

    my_data_t* my_data = g_try_new0(my_data_t, 1);
    if (my_data != NULL) {
        my_data->a = 100;
        my_list = g_list_append(my_list, (gpointer)my_data);
        log_debug("listdata pushed:%d\n", my_data->a);
    }

    gint my_custom = 1;
    g_list_foreach(my_list, my_func, &my_custom);
    g_list_free_full(g_steal_pointer(&my_list), (GDestroyNotify)my_free);

    if (my_list == NULL) {
        log_debug("listdata empty\n");
    }

    return 0;
}
