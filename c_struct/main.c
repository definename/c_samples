#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_util.h"

#include "test_struct_compound_literal.h"
#include "test_anonymous_struct.h"

struct
{
  int a;
  int b;
} static const desc[] =
{
  {1, 11},
  {2, 22}
};

typedef struct {
  int i;
  const int j;
  char* name;
  const char* name_const;
} test_t;

#define TEST_NAME "NAME"

#define TEST_DEFAULT \
{ \
  .i = 11, \
  .j = 22, \
  .name = NULL, \
  .name_const = TEST_NAME, \
} \

void test_leak(const char* name);

int main (int argc, const char *argv[]) {
  //.....................................................
  const size_t size = sizeof desc /sizeof desc[0];
  for (size_t i = 0; i < size; ++i) {
    printf("%d %d\n", desc[i].a, desc[i].b);
  }

  //.....................................................
  test_t t = {11, 22};
  printf("ti: %d tj:%d\n", t.i, t.j);

  //.....................................................
  test_t test = TEST_DEFAULT;
  printf("i:%d j:%d name:%s\n", test.i, test.j, test.name_const);

  //.....................................................
  test_leak(TEST_NAME);

  test_struct_compound_literal();

  test_anonymous_struct();
  return 0;
}

void test_leak(const char* name) {
  test_t t = {.i = 1, .j = 2};
  size_t size = strlen(name) + 1;
  t.name = malloc(sizeof(char) * size);
  strcpy(t.name, name);
  printf("t name:%s %p\n", t.name, t.name);

  test_t tt = t;
  printf("tt name:%s %p\n", tt.name, tt.name);

  free(tt.name);
}