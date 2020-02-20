#include "hash_util.h"
#include "test_util.h"

void hash_init(hash_t *h) {
  h->head = NULL;
}

void add_item(hash_t *h, hash_item_t *item) {
  hash_item_t *i;
  i = get_item(h, item->id);
  if (i != NULL){
    printf("Item:%d already in hash, delete it\n", i->id);
    HASH_DEL(h->head, i);
  }
  printf("Item is being added to the hash:%d\n", item->id);
  HASH_ADD_INT(h->head, id, item);
}

hash_item_t *get_item(hash_t *h, int id) {
  printf("Get item:%d from hash\n", id);
  hash_item_t *i;
  HASH_FIND_INT(h->head, &id, i);
  return i;
}

void delete_item(hash_t *h, hash_item_t *item) {
  HASH_DEL(h->head, item);
}
