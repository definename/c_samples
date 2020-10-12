#include <glib.h>
#include <glib/gprintf.h>

#define log_debug(format, ...) g_printf(format, ##__VA_ARGS__)

int main (int argc, const char * argv[]) {
    // build
    GVariantBuilder *my_variant_builder = g_variant_builder_new(G_VARIANT_TYPE("a(ss)"));
    g_variant_builder_add(my_variant_builder, "(ss)", "my_value1", "my_value11");
    g_variant_builder_add(my_variant_builder, "(ss)", "my_value2", "my_value22");
    GVariant *my_variant_array = g_variant_new("a(ss)", my_variant_builder);

    // iterate
    GVariantIter *iter = NULL;
    gchar* str1 = NULL;
    gchar* str2 = NULL;

    g_variant_get(my_variant_array, "a(ss)", &iter);
    while (g_variant_iter_loop(iter, "(ss)", &str1, &str2) == TRUE) {
        log_debug("%s, %s\n", str1, str2);
    }
    g_variant_iter_free(iter);

    // free
    g_variant_builder_unref(my_variant_builder);
    g_variant_unref(my_variant_array);

    return 0;
}
