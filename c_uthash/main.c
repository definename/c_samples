#include <stdlib.h>
#include <string.h>

#include "test_util.h"
#include "hash_util.h"

int main (int argc, const char * argv[]) {

  char name[] = "Name";
  // Memory leak here.
  hash_item_t *item = malloc(sizeof(hash_item_t));
  item->id = 99;
  strcpy(item->name, name);

  hash_t test_hash;
  hash_init(&test_hash);

  add_item(&test_hash, item);
  add_item(&test_hash, item);

  hash_item_t *got_item;
  got_item = get_item(&test_hash, item->id);
  printf("%p, %p\n", got_item, item);
  if (got_item){
    printf("Got item with id:%d\n", got_item->id);

    delete_item(&test_hash, got_item);
    if (get_item(&test_hash, got_item->id)){
      printf("Item:%d is still in hash\n", got_item->id);
    }
    else{
      printf("Item:%d has been deleted from hash\n", got_item->id);
    }
  }
  return 0;
}
