#include <stdio.h>
#include <stdlib.h>

#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)

int main (int argc, const char * argv[]){
  printf("Macro stringify:%s\n", g(f(1,2)));
  printf("Macro concatenate:%s\n", h(f(1,2)));
  return 0;
}
