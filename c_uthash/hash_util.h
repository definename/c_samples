#ifndef HASH_UTIL
#define HASH_UTIL

#include "uthash/uthash.h"
#include <stdbool.h>

typedef struct {
  int id;
  char name[10];
  UT_hash_handle hh;
} hash_item_t;

typedef struct {
  hash_item_t *head;
} hash_t;

void hash_init(hash_t *h);
hash_item_t* add_item_int(hash_t *h, hash_item_t *item);
hash_item_t *get_item(hash_t *h, int id);
void delete_item(hash_t *h, hash_item_t *item);
size_t get_size(hash_t *h);

#endif // HASH_UTIL