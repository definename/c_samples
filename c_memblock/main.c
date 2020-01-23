#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main (int argc, const char * argv[]) {
  printf("int size:%zu\n", sizeof(int));

  int *x = malloc(sizeof(int));
  *x = 333;
  int *y = malloc(sizeof(int));
  *y = 444;

  void *z = malloc(sizeof x + sizeof y);
  memcpy(z, x, sizeof x);
  memcpy(z + sizeof x, y, sizeof y);

  printf("x val:%d\n", *(int*)z);
  printf("y val:%d\n", *(int*)(z + sizeof x));

  free(z);
  free(x);
  free(y);

  return 0;
}
