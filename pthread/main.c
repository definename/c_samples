#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
#include <stdbool.h>

void *t_handler(void* t_data){
  printf("We are here!!!\n");
  pthread_exit(0);
}

void test_bool(const bool ret){
  printf("%s\n", ret ? "true" : "false");
}

int main(){
  void* t_data = NULL;
  pthread_t t;
  pthread_create(&t, NULL, t_handler, t_data);

  pthread_join(t, NULL);

  test_bool(true);
  test_bool(false);
  return 0;
}