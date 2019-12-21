#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_first_n(int* arr, const int n);
void show_first_n(int* arr, const int n);

int main (int argc, const char * argv[]) {
  int* pa = malloc(sizeof(int) * 10);
  if (pa) {
    printf("malloc ok\n");
    fill_first_n(pa, 10);

    const int realloc_to = 2;

    int* pb = realloc(pa, sizeof(int) * realloc_to);
    if (pb) {
      printf("realloc ok\n");
      show_first_n(pb, realloc_to);
      free(pb);
    } else {
      free(pa);
    }
  }
  return 0;
}

void fill_first_n(int* arr, const int n) {
  for (int i = 0; i < n; ++i) {
      printf("%d\n", arr[i] = i);
    }
}

void show_first_n(int* arr, const int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d\n", arr[i]);
  }
}