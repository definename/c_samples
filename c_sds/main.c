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

  s = sdscpy(s, "new");

  // Segmentation fault here.
  // const int n = sdscmp(s, NULL);

  // Segmentation fault here.
  // sds origin = NULL;
  // sds dup = sdsdup(origin);

  test_sds(s);

  sdsfree(s);
  s = NULL;
  return 0;
}

void test_sds(const char* str) {
  printf("%s\n", str);
}
