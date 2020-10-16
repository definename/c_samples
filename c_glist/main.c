#include <glib/gprintf.h>

#define log_debug(format, ...) g_printf(format, ##__VA_ARGS__)

typedef struct {
    gint a;
} my_data_t;

void my_foraech_func(gpointer list_data, gpointer user_data) {
    my_data_t* l_data = (my_data_t*)list_data;
    gint* u_data = (gint*) user_data;
    log_debug("listdata:%d, userdata:%d\n", l_data->a, *u_data);
}

gint my_find_custom_func(gconstpointer a, gconstpointer b) {
    log_debug("listfind custom called\n");
    my_data_t* ptr1 = (my_data_t*)a;
    my_data_t* ptr2 = (my_data_t*)b;
    if (ptr1->a == ptr2->a) {
        return 0; // found
    }
    return 1; // not found
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
    g_list_foreach(my_list, my_foraech_func, &my_custom);

    my_data_t my_data_to_find = { 101 };
    GList* item = g_list_find_custom(my_list,
                                    (gconstpointer)&my_data_to_find,
                                    (GCompareFunc)my_find_custom_func);
    if (item == NULL) {
        log_debug("listitem not found\n");
    } else {
        my_data_t* i = (my_data_t*)item->data;
        log_debug("listitem found:%d\n", i->a);
    }

    g_list_free_full(g_steal_pointer(&my_list), (GDestroyNotify)my_free);
    if (my_list == NULL) {
        log_debug("listdata empty\n");
    }

    return 0;
}
