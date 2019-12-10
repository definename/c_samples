#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_sort(int* arr, const int size);
void bubble_sort(int* arr, const int size);

void print_arr(int* arr, const int size);

int main (int argc, const char * argv[]) {
  int arr[] = { 1, 2, 90, 4, 2, 2, 299, 3 };
  const int size = sizeof arr/sizeof(int);

  printf("Insertion sort.........\n");
  int* arr_insert = malloc(size);
  memcpy(arr_insert, arr, size * sizeof(int));
  insert_sort(arr_insert, size);
  free(arr_insert);

  printf("Bubble sort.........\n");
  int* arr_bubble = malloc(size);
  memcpy(arr_bubble, arr, size * sizeof(int));
  bubble_sort(arr_bubble, size);
  free(arr_bubble);

  return 0;
}

void bubble_sort(int* arr, const int size) {
  print_arr(arr, size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - 1; ++j) {
      if (arr[j] > arr[j+1]) {
        printf("swap %d %d\n", arr[j], arr[j+1]);
        int tmp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = tmp;
        print_arr(arr, size);
      }
    }
  }
  print_arr(arr, size);
}

void insert_sort(int* arr, const int size) {
  print_arr(arr, size);
  for (int i = 1; i < size; ++i) {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j])
    {
      printf("swap %d %d\n", arr[j], arr[j-1]);
      int tmp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = tmp;
      --j;
      print_arr(arr, size);
    }
  }
  print_arr(arr, size);
}

void print_arr(int* arr, const int size) {
    for(int i = 0; i < size; ++i) {
      printf("%d ", arr[i]);
    }
    printf("\n");
}
