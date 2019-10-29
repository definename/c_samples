#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
// Test
#include <stdbool.h>
#include <string.h>

void *t_handler(void* t_data){
  printf("We are here!!!\n");
  pthread_exit(0);
}

void test_bool(const bool ret){
  printf("%s\n", ret ? "true" : "false");
}

typedef struct{
  int a;
  int b; 
} test_struct_t;

void test_memset(void){
  test_struct_t test_struct;
  printf("test memset:%d %d\n", test_struct.a, test_struct.b);
  memset(&test_struct, 0, sizeof(test_struct_t));
  printf("test memset:%d %d\n", test_struct.a, test_struct.b);
}

void test_struct_init(test_struct_t *test){
  if (test){
    test->a = 1;
    test->b = 2;
  }
  else{
    printf("Invalid struct pointer was given\n");
  }
}


int main(){
  void* t_data = NULL;
  pthread_t t;
  pthread_create(&t, NULL, t_handler, t_data);

  pthread_join(t, NULL);

  // .....................................................
  test_bool(true);
  test_bool(false);
  bool b;
  if (b){
    printf("111\n");
  }

  // .....................................................
  test_memset();

  // .....................................................
  test_struct_t test_struct;
  test_struct_init(&test_struct);
  printf("test struct init:%d %d\n", test_struct.a, test_struct.b);
  test_struct_init(NULL);

  return 0;
}