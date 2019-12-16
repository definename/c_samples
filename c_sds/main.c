#include <stdio.h>
#include <stdlib.h>
#include "sds.h"

void test_sds(const char* str);

int main (int argc, const char * argv[]){
  sds s = sdsempty();
  s = sdscat(s, "Hello");
  s = sdscat(s, " World");
  s = sdscat(s, " from");
  s = sdscat(s, " sds!!");

  test_sds(s);

  sdsfree(s);
  return 0;
}

void test_sds(const char* str) {
  printf("%s\n", str);
}
