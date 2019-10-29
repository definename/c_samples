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
  printf("%d %d\n", test_struct.a, test_struct.b);
  memset(&test_struct, 0, sizeof(test_struct_t));
  printf("%d %d\n", test_struct.a, test_struct.b);
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

  return 0;
}