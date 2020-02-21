#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#include "test_util.h"
#include "hash_util.h"

uint64_t get_hash(const char* some_str) {
    uint64_t hashv = 0;
    HASH_VALUE(some_str, strlen(some_str), hashv);
    return hashv;
}

int main (int argc, const char * argv[]) {
    int count = 1;
    char name[] = "Name1";
    while (count)
    {
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

        uint64_t hashv = get_hash(name);
        log_debug("%"PRIu64"\n", hashv);
    }
    return 0;
}
