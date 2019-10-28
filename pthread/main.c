#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

void *t_handler(void* t_data){
  printf("We are here!!!\n");
  pthread_exit(0);
}

int main(){
  void* t_data = NULL;
  pthread_t t;
  pthread_create(&t, NULL, t_handler, t_data);

  pthread_join(t, NULL);
  return 0;
}