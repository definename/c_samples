#include <stdbool.h>
#include <stdlib.h>
#include "test_util.h"

#include "test_double_free.h"
#include "test_free.h"

void test_no_double_free(void) {
  while (true) {
    int* i = malloc(sizeof(int));
    *i = 111;
    log_debug("%d %p\n", *i, i);
    free(i);
    log_debug("No double free\n");
    i = NULL;
    free(i);
  }
}

void test_double_free(void) {
  while (true) {
    int* i = malloc(sizeof(int));
    test_free(i);
    if (i) {
      log_debug("Double free!!!\n");
      free(i);
    }
  }
}