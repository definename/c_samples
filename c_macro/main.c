#include <stdio.h>
#include <stdlib.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

#define CONCATENATE(a,b) a##b
#define STRINGIFY(a) #a
#define CASE_TO_STR(x) case x: return STRINGIFY(x);

#define AS_IS(a) a
#define ITEM_LIST(ADD_FUNC)   \
    ADD_FUNC(ONE_ITEM),       \
    ADD_FUNC(TWO_ITEM),       \

char* item_names[] = { ITEM_LIST(STRINGIFY) };

typedef enum {
    ITEM_LIST(AS_IS)
    ITEM_UNKNOWN,
} item_t;

const char* item_to_str(const item_t item) {
    switch(item) {
        CASE_TO_STR(ONE_ITEM)
        CASE_TO_STR(TWO_ITEM)
        default:
        return STRINGIFY(ITEM_UNKNOWN);
    }
}

const char* item_to_str2(const item_t item) {
    if (item >= 0 && item < ITEM_UNKNOWN) {
        return item_names[item];
    } else {
        return STRINGIFY(ITEM_UNKNOWN);
    }
}

int main (int argc, const char * argv[]) {
  printf("Concatenate:%d\n", CONCATENATE(1,2));
  printf("Stringify:%s\n", STRINGIFY(teststring));

  for (int i = 0; i <= ITEM_UNKNOWN; ++i) {
    log_debug("%s(%d)\n", item_to_str(i), i);
  }

  for (int i = 0; i <= ITEM_UNKNOWN; ++i) {
    log_debug("%s(%d)\n", item_to_str2(i), i);
  }
  return 0;
}
