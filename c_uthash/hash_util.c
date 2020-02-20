#include "hash_util.h"
#include "test_util.h"

void hash_init(hash_t *h) {
  h->head = NULL;
}

bool add_item(hash_t *h, hash_item_t *item) {
    bool res = false;
    hash_item_t *i = NULL;
    i = get_item(h, item->id);
    if (i == NULL) {
        log_debug("Item is being added to the hash:%d\n", item->id);
        HASH_ADD_INT(h->head, id, item);
        res = true;
    }
    return res;
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
