#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "def.h"

void _range_clear (range_void * range)
{
    free (range->begin);
}

void _range_realloc_new (range_void * range, size_t member_size)
{
    size_t have_size = (char*) range->end - (char*) range->begin;

    range->begin = realloc (range->begin, have_size + member_size);

    range->end = (char*) range->begin + have_size;
}
