#include <stdio.h>

void insert_sort(int* arr, const int size);
void print_arr(int* arr, const int size);

int main (int argc, const char * argv[]) {
  // Insertion sort.
  int arr[] = { 1, 2, 90, 4, 2, 2, 299, 3 };
  const int size = sizeof arr/sizeof(int);
  insert_sort(arr, size);
  print_arr(arr, size);

  return 0;
}

void insert_sort(int* arr, const int size) {
  for (int i = 1; i < size; ++i) {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j])
    {
      int tmp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = tmp;
      --j;
    }
  }
}

void print_arr(int* arr, const int size) {
    for(int i = 0; i < size; ++i) {
      printf("%d ", arr[i]);
    }
}
