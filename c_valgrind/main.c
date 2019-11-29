#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_test(int i) {
  int delta = 123;
  char* mem = malloc(1024);
  strcpy(mem, "i = ");
  printf("%s %d\n", mem, i + delta);
  free(mem);
}

int main (int argc, const char * argv[]) {
  printf("It works!!!\n");
  size_t size = 1;
  for(int i = 0; i < size; i++) {
    run_test(i);
  }
  return 0;
}
