#include <stdio.h>
#include <string.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__);

void c_loop1(void) {
  char ch;
  while ((ch = getchar()) != 'q') {
    putchar(ch);
  }
}

void c_loop2(void) {
  int i;
  while (scanf("%d", &i)) {
    log_debug("%d\n", i);
  }
}

int main (int argc, const char *argv[]) {
  log_debug("Loop1\n");
  c_loop1();
  log_debug("Loop2\n");
  c_loop2();
  return 0;
}
