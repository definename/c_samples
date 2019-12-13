#include <stdio.h>
#include <stdlib.h>

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
  const char* name;
} test_t;

#define TEST_DEFAULT \
{ \
  .i = 11, \
  .j = 22, \
  .name = "NAME", \
} \

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
  printf("i:%d j:%d name:%s\n", test.i, test.j, test.name);

  return 0;
}