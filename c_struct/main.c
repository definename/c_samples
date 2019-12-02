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
} test_t;

int main (int argc, const char *argv[]){
  const size_t size = sizeof desc /sizeof desc[0];
  for (size_t i = 0; i < size; ++i){
    printf("%d %d\n", desc[i].a, desc[i].b);
  }

  test_t t = {11, 22};
  printf("ti: %d tj:%d\n", t.i, t.j);
  return 0;
}