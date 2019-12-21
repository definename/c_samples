#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data_t;

void test_func(data_t** data);

int main (int argc, const char * argv[]) {
  data_t* data;
  test_func(&data);
  if (data) {
    printf("data is not null:%s\n", data);
    free(data);
  } else {
    printf("data is null\n");
  }
  return 0;
}

void test_func(data_t** data) {
  *data = NULL;
  *data = malloc(sizeof(data_t) * 10);
  strcpy(*data, "data");
}
