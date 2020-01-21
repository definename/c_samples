#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data_t;

typedef struct {
  data_t* data;
} test_data_t;

void test_func(data_t** data);

void test_func1(test_data_t* test_data);
void test_func2(test_data_t* test_data);

int main (int argc, const char * argv[]) {
  // .......................................
  data_t* data;
  test_func(&data);
  if (data) {
    printf("data is not null:%s\n", data);
    free(data);
  } else {
    printf("data is null\n");
  }
  // .......................................
  for (int i = 0; i < 100; ++i) {
    test_data_t* test_data = malloc(sizeof(test_data_t));
    if (test_data){
      test_func1(test_data);
      if (test_data->data) {
        printf("data is not null:%s\n", test_data->data);
        free(test_data->data);
      } else {
        printf("data is null\n");
        break;
      }
      free(test_data);
    } else {
      printf("test data is null");
      break;
    }
  }
  return 0;
}

void test_func(data_t** data) {
  *data = NULL;
  *data = malloc(sizeof(data_t) * 10);
  strcpy(*data, "data");
}

void test_func1(test_data_t* test_data) {
  test_func2(test_data);
}

void test_func2(test_data_t* test_data) {
  test_data->data = malloc(sizeof(data_t) * 10);
  strcpy(test_data->data, "data");
}