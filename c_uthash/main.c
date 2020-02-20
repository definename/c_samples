#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash/uthash.h"

typedef struct {
  int id;
  char name[10];
  UT_hash_handle hh;
} hash_item_t;

typedef struct {
  hash_item_t *head;
} hash_t;

hash_t test_hash;

void hash_init(hash_t *h);
void add_item(hash_item_t* item);
hash_item_t *get_item(int id);
void delete_item(hash_item_t *item);

int main (int argc, const char * argv[]){

  char name[] = "Name";
  hash_item_t *item = malloc(sizeof(hash_item_t));
  item->id = 99;
  strcpy(item->name, name);

  hash_init(&test_hash);

  add_item(item);
  add_item(item);

  hash_item_t *got_item;
  got_item = get_item(item->id);
  printf("%p, %p\n", got_item, item);
  if (got_item){
    printf("Got item with id:%d\n", got_item->id);

    delete_item(got_item);
    if (get_item(got_item->id)){
      printf("Item:%d is still in hash\n", got_item->id);
    }
    else{
      printf("Item:%d has been deleted from hash\n", got_item->id);
    }
  }
  return 0;
}

void hash_init(hash_t *h){
  h->head = NULL;
}

void add_item(hash_item_t *item){
  hash_item_t *i;
  i = get_item(item->id);
  if (i != NULL){
    printf("Item:%d already in hash, delete it\n", i->id);
    HASH_DEL(test_hash.head, i);
  }
  printf("Item is being added to the hash:%d\n", item->id);
  HASH_ADD_INT(test_hash.head, id, item);
}

hash_item_t *get_item(int id){
  printf("Get item:%d from hash\n", id);
  hash_item_t *i;
  HASH_FIND_INT(test_hash.head, &id, i);
  return i;
}

void delete_item(hash_item_t *item){
  HASH_DEL(test_hash.head, item);
}

