#include <stdio.h>
#include <assert.h>
#include "config.h"

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

int main (int argc, const char *argv[]) {
  log_debug("Check static assert!!\n");
  return 0;
}