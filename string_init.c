#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

void range_string_init (range_const_char * target, const char * input)
{
    target->begin = input;
    target->end = input + strlen(input);
}
