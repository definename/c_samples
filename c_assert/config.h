#ifndef CONFIG_H
#define CONFIG_H

#include "stddef.h"
#include "test_util.h"

typedef struct {
    int key;
    const char* value;
} key_value_t;

#endif // CONFIG_H