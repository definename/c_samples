#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
  for (size_t i = 0; i < sizeof(desc)/sizeof(desc[0]); ++i){
    printf("%d %d\n", desc[i].a, desc[i].b);
  }
  return 0;
}