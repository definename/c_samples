#include <stdio.h>
#include <malloc.h>

#include "test_compound_literal.h"

#define COUNT_OF(arr) (sizeof(arr)/sizeof(arr[0]))
#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

void test_2d_array(unsigned int count);
void test_loop_array1(int arr[], const size_t size);
void test_loop_array2(int* start, int* end);

int main (int argc, const char * argv[]) {
  // test_2d_array(1);

  // int arr[] = { 1, [9] = 10 };
  // test_loop_array1(arr, COUNT_OF(arr));
  // test_loop_array2(arr, arr + COUNT_OF(arr));

  test_compound_literal_arr1d();
  test_compound_literal_arr2d();

  return 0;
}

void test_2d_array(unsigned int count) {
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
}

void test_loop_array1(int arr[], const size_t size) {
  for (size_t i = 0; i < size; ++i) {
    log_debug("%d, ", arr[i]);
  }
  log_debug("\n");
}

void test_loop_array2(int* start, int* end) {
  while (start < end) {
    log_debug("%d, ", *start);
    ++start;
  }
  log_debug("\n");
}