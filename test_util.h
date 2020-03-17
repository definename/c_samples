#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <stdio.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)
#define COUNT_OF(arr) (sizeof(arr) / sizeof(arr[0]))
#define STRSAFE(s) ((s) ? (s) : "(null)")

#endif // TEST_UTIL_H