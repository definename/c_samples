#include "config.h"
#include "assert.h"

const key_value_t config[] = {
    {0, "value1"},
    {1, "value2"},
    {2, "value2"},
};
const size_t config_size = COUNT_OF(config);

static_assert(COUNT_OF(config) == COUNT_OF(config), "Config size is incorrect");