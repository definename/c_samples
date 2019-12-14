#include <stdio.h>
#include <stdlib.h>

#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)

#define ENUM_TO_STR(e) #e

typedef enum {
  ONE_ITEM,
  TWO_ITEM,
  ITEM_UNKNOWN
} item_t;

#define CASE_TO_STR(x) case x: return ENUM_TO_STR(x);

const char* item_to_str(int item) {
  const char* ret;
  switch(item) {
    case ONE_ITEM: ENUM_TO_STR(ONE_ITEM);
    CASE_TO_STR(TWO_ITEM)
    default:
    return ENUM_TO_STR(ITEM_UNKNOWN);
  }
}

int main (int argc, const char * argv[]){
  printf("Macro stringify:%s\n", g(f(1,2)));
  printf("Macro concatenate:%s\n", h(f(1,2)));

  printf("..%s\n", ENUM_TO_STR(ONE_ITEM));

  for (int i = 0; i < 4; ++i) {
    printf("%s(%d)\n", item_to_str(i), i);
  }
  return 0;
}
