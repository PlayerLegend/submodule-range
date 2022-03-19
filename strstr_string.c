#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

size_t range_strstr_string (const range_const_char * haystack, const char * needle)
{
    range_const_char needle_range = { .begin = needle, .end = needle + strlen (needle) };

    return range_strstr(haystack, &needle_range);
}
