#ifndef CONFIG_H
#define CONFIG_H

#include "stddef.h"

#define COUNT_OF(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct {
    int key;
    const char* value;
} key_value_t;

#endif // CONFIG_H