#include "hash_util.h"
#include "test_util.h"

void hash_init(hash_t *h) {
  h->head = NULL;
}

hash_item_t* add_item_int(hash_t *h, hash_item_t *item) {
    hash_item_t *item_replaced = NULL;
    HASH_REPLACE_INT(h->head, id, item, item_replaced);
    log_debug("Item is being added to the hash:%d\n", item->id);
    return item_replaced;
}

hash_item_t *get_item(hash_t *h, int id) {
  log_debug("Get item:%d from hash\n", id);
  hash_item_t *i = NULL;
  HASH_FIND_INT(h->head, &id, i);
  return i;
}

void delete_item(hash_t *h, hash_item_t *item) {
  HASH_DEL(h->head, item);
}

size_t get_size(hash_t *h) {
    return HASH_COUNT(h->head);
}
