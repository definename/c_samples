#include <stdio.h>
#include <malloc.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

int main (int argc, const char * argv[]) {

  int count = 1;
  while (count)
  {
    int **a;
    a = malloc(10 * sizeof(int*));
    //a = malloc(10 * sizeof(*a));
    if (a) {
      for (int i = 0; i < 10; ++i) {
        a[i] = malloc(sizeof(int));
        //a[i] = malloc(sizeof(**a));
        *a[i] = i;
      }

      for (int i = 0; i < 10; ++i) {
        log_debug("%d, ", *a[i]);
      }
      log_debug("\n");

      for (int i = 0; i < 10; ++i) {
        free(a[i]);
      }
      free(a);
    }
    --count;
  }

  return 0;
}
