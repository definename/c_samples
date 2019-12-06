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

void test_enum_to_str(const item_t item) {
  switch(item) {
    case ONE_ITEM:
    printf("%s\n", ENUM_TO_STR(ONE_ITEM));
    break;
    case TWO_ITEM:
    printf("%s\n", ENUM_TO_STR(ONE_ITEM));
    break;
    default:
    printf("%s\n", ENUM_TO_STR(ITEM_UNKNOWN));
  }
}

int main (int argc, const char * argv[]){
  printf("Macro stringify:%s\n", g(f(1,2)));
  printf("Macro concatenate:%s\n", h(f(1,2)));

  test_enum_to_str(ONE_ITEM);
  test_enum_to_str(TWO_ITEM);
  test_enum_to_str(99);
  return 0;
}
