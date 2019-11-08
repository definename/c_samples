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

int main (int argc, const char *argv[]){
  const size_t size = sizeof(desc)/sizeof(desc[0]);
  for (size_t i = 0; i < size; ++i){
    printf("%d %d\n", desc[i].a, desc[i].b);
  }
  return 0;
}