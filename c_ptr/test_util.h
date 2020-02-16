#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <stdio.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__)

#endif // TEST_UTIL_H