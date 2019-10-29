#include <stdio.h>
#include <stdlib.h>

void my_swap(int *a, int *b);
void test_swap(void);

void test_array(void);

int main (int argc, const char *argv[]){

  test_swap();
  test_array();

  return 0;
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
