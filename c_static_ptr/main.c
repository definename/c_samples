#include <stdio.h>
#include <string.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

void get(char **odata);

int main (int argc, const char *argv[]) {
  int count = 1000;
  while (count--)
  {
    static char *got;

    get(&got);
    log_debug("It works:%s\n", got);
    free(got);

    get(&got);
    log_debug("It works:%s\n", got);
    free(got);
  }
  return 0;
}

void get(char **odata) {
  char data[] = "data";
  const size_t size = sizeof data / sizeof data[0];
  log_debug("data:%s\n", data);
  log_debug("data size:%zu\n", size);

  *odata = malloc(size);
  memcpy(*odata, data, size);
  log_debug("Alloc\n");
}
