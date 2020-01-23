#include <stdio.h>
#include <stdlib.h>

#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)

typedef enum {
  ONE_ITEM = 0,
  TWO_ITEM,
  ITEM_UNKNOWN
} item_t;

#define ENUM_TO_STR(e) #e
#define CASE_TO_STR(x) case x: return ENUM_TO_STR(x);
#define LOG_DEBUG(format, ...) printf(format, ##__VA_ARGS__)

const char* item_to_str(item_t item) {
  switch(item) {
    CASE_TO_STR(ONE_ITEM)
    CASE_TO_STR(TWO_ITEM)
    default:
    return ENUM_TO_STR(ITEM_UNKNOWN);
  }
}

int main (int argc, const char * argv[]){
  LOG_DEBUG("No data\n");
  LOG_DEBUG("Data:%d\n", 1);

  printf("MACRO stringify:%s\n", g(f(1,2)));
  printf("MACRO concatenate:%s\n", h(f(1,2)));

  for (int i = 0; i < 3; ++i) {
    printf("%s(%d)\n", item_to_str(i), i);
  }
  return 0;
}
