#include <stdio.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__);

// Convert decimal to binary using recursion.
void to_binary(unsigned long n);

int main (int argc, const char *argv[]) {
  unsigned long l;
  while (scanf("%lu", &l) == 1) {
    to_binary(l);
    log_debug("\n");
  }
  return 0;
}

void to_binary(unsigned long n) {
  unsigned int r = n % 2;
  if (n >= 2) {
    to_binary(n / 2);
  }
  log_debug("%c", r == 0 ? '0' : '1');
  return;
}
