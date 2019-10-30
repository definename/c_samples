#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void my_swap(int *a, int *b);
void test_swap(void);

void test_array(void);

void test_func_ptr(void);
typedef void(*request_done_t)(bool ok);
typedef struct{
  int data;
  request_done_t done;
} request_t;

int main (int argc, const char *argv[]){

  test_swap();
  test_array();
  test_func_ptr();

  return 0;
}

// .......................................................

void request_done_handler(bool ok){
  printf("request done handler:%d\n", ok);
}

void test_func_ptr(void){
  request_t *req = (request_t *)malloc(sizeof(request_t));
  if (req){
    req->data = 99;
    req->done = request_done_handler;
  }
  req->done(true);
  req->done(false);
}

// .......................................................
void test_array(void){
  size_t size = 2;
  int *parray = (int *)malloc(size * sizeof(int));
  for (size_t i = 0; i < size; ++i){
    parray[i] = i + 100;
  }

  for (size_t i = 0; i < size; ++i){
    printf("test array:%d\n", parray[i]);
  }
  free(parray);
}

// .......................................................
void test_swap(void){
  int a = 0;
  int b = 1;
  printf("test swap a:%d b:%d\n", a, b);
  my_swap(&a, &b);
  printf("test swap a:%d b:%d\n", a, b);
}

void my_swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
