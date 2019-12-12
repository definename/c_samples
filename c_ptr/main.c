#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void my_swap(int *a, int *b);
void test_swap(void);

void test_array(void);

void test_func_ptr(void);
void request_done_handler(bool ok);
typedef void(*request_done_t)(bool ok);
typedef struct{
  int data;
  request_done_t done;
} request_t;
request_t* init_request(request_done_t done, int data);

typedef int MyInt;
typedef MyInt * MyIntPtr;
void test_alias(void);

void test_free(int* i);

int main (int argc, const char *argv[]) {
  // test_swap();
  // test_array();
  // test_func_ptr();
  // test_alias();

  while (true) {
    int* i = malloc(sizeof(int));
    test_free(i);
    if (i) {
      printf("Double free!!!\n");
      free(i);
    }
  }

  return 0;
}

void test_free(int* i) {
  *i = 1;
  printf("%d\n", *i);
  free(i);
  i = NULL;
}

// .......................................................
void test_alias(void){
  MyInt i = 1;
  printf("myint:%d\n", i);

  MyIntPtr i_ptr = (MyIntPtr)malloc(sizeof(MyInt));
  *i_ptr = 11;
  printf("myint ptr:%d\n", *i_ptr);
  free(i_ptr);
}

// .......................................................

void request_done_handler(bool ok){
  printf("request done handler:%d\n", ok);
}

request_t* init_request(request_done_t done, int data){
  request_t *req = NULL;
  req = (request_t *)malloc(sizeof(request_t));
  if (req){
    req->data = data;
    req->done = done;
  }
  return req;
}

void test_func_ptr(void){
  request_t *req = init_request(request_done_handler, 99);
  if (req){
    printf("request data:%d\n", req->data);
    if (req->done){
      req->done(true);
      req->done(false);
    }
  }
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
