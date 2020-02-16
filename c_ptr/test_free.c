#include <stdio.h>
#include <stdlib.h>
#include "test_free.h"

void test_free(int* i) {
  *i = 1;
  printf("%d\n", *i);
  free(i);
  i = NULL;
}