#include <math.h>
#include <time.h>
#include <inttypes.h>
#include "test_util.h"

int main (int argc, const char * argv[]) {
  long ms = 0;
  time_t s = 0;
  struct timespec ts = {0};
  clock_gettime(CLOCK_REALTIME, &ts);

  s  = ts.tv_sec;
  ms = round(ts.tv_nsec / 1.0e6);
  if (ms > 999) {
      s++;
      ms = 0;
  }

  // Retrieve expected size.
  const int sz = snprintf(NULL, 0, "%010ld%03ld", s, ms);
  log_debug("Expected timestamp size:%d\n", sz);

  // Build string representation of timestamp.
  char input_str[sz + 1];
  sprintf(input_str, "%010ld%03ld", s, ms);
  log_debug("Input str:%s\n", input_str);

  // Convert string to uint64_t.
  uint64_t timestamp_milisec = 0;
  sscanf(input_str, "%"PRIu64, &timestamp_milisec);
  log_debug("Timestamp:%"PRIu64"\n", timestamp_milisec);

  return 0;
}
