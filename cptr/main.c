#include <stdio.h>

void my_swap(int *a, int *b);
void test_swap(void);

int main (int argc, const char *argv[]){
  test_swap();
  return 0;
}

void test_swap(void){
  int a = 0;
  int b = 1;
  printf("a:%d b:%d\n", a, b);
  my_swap(&a, &b);
  printf("a:%d b:%d\n", a, b);
}

void my_swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
