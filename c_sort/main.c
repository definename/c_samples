#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "test_util.h"

void bubble_sort(int32_t arr[], const size_t size);
void insertion_sort(int32_t arr[], const size_t size);
void selection_sort(int32_t arr[], const size_t size);

static void swap(int32_t *a, int32_t *b);
static void print_arr(int32_t arr[], const size_t size);

int main (int argc, const char * argv[]) {
    int arr[] = { 1, 2, -1, 90, 4, 2, 2, 299, 3 };
    const int size = COUNT_OF(arr);

    log_debug("Insertion sort.........\n");
    int* arr_insert = malloc(size * sizeof(int32_t));
    memcpy(arr_insert, arr, size * sizeof(int));
    insertion_sort(arr_insert, size);
    free(arr_insert);

    log_debug("Bubble sort............\n");
    int* arr_bubble = malloc(size * sizeof(int32_t));
    memcpy(arr_bubble, arr, size * sizeof(int));
    bubble_sort(arr_bubble, size);
    free(arr_bubble);

    log_debug("Selection sort.........\n");
    int32_t *arr_select = malloc(size * sizeof(int32_t));
    memcpy(arr_select, arr, size * sizeof(int32_t));
    selection_sort(arr_select, size);

  return 0;
}

void bubble_sort(int32_t arr[], const size_t size) {
    print_arr(arr, size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
        print_arr(arr, size);
    }
}

void insertion_sort(int32_t arr[], const size_t size) {
    print_arr(arr, size);
    for (size_t i = 1; i < size; ++i) {
        size_t j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(&arr[j], &arr[j-1]);
            --j;
        }
        print_arr(arr, size);
    }
}

void selection_sort(int32_t arr[], const size_t size) {
    print_arr(arr, size);
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
        print_arr(arr, size);
    }
}

static void print_arr(int32_t arr[], const size_t size) {
    for(size_t i = 0; i < size; ++i) {
      log_debug("%"PRId32" ", arr[i]);
    }
    log_debug("\n");
}

static void swap(int32_t *a, int32_t *b) {
  log_debug("swap %"PRId32" %"PRId32"\n", *a, *b);
  int32_t tmp = *a;
  *a = *b;
  *b = tmp;
}