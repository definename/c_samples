#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>

#define log_debug(format, ...) printf(format, ##__VA_ARGS__);

#endif // TYPES_H