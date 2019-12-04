#include <stdio.h>
#include <string.h>

int main (int argc, const char * argv[]) {

  char* test_str;
  test_str = NULL;
  if (test_str) {
    char* test_str_dup = strdup(test_str);
    if (test_str_dup) {
      printf("Test str dup is ok\n");
    } else {
      printf("Test str dup is nok\n");
    }
  } else {
    printf("Test str is null\n");
  }

  return 0;
}
