#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "test_util.h"
#include "hash_util.h"

int main (int argc, const char * argv[]) {
    int count = 1;
    while (count)
    {
        char name[] = "Name1";
        hash_item_t *item = malloc(sizeof(hash_item_t));
        item->id = 99;
        strcpy(item->name, name);

        hash_t test_hash;
        hash_init(&test_hash);

        hash_item_t *item_replaced = NULL;
        if (!(item_replaced = add_item_int(&test_hash, item))) {
            log_debug("Item with id:%d was NOT found in hash\n", item->id);
        }
        if ((item_replaced = add_item_int(&test_hash, item))) {
            log_debug("Item with id:%d was found in hash\n", item->id);
        }

        size_t c = get_size(&test_hash);
        log_debug("Hash size:%zu\n", c);

        hash_item_t *got_item = NULL;
        got_item = get_item(&test_hash, item->id);
        log_debug("%p, %p\n", got_item, item);
        if (got_item){
            log_debug("Got item id:%d name:%s\n", got_item->id, got_item->name);

            delete_item(&test_hash, got_item);
            if (get_item(&test_hash, got_item->id)) {
                log_debug("Item:%d is still in hash\n", got_item->id);
            }
            else {
                log_debug("Item:%d has been deleted from hash\n", got_item->id);
            }
            free(got_item);
            got_item = NULL;
        }
        --count;
    }
    return 0;
}
