#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

bool range_streq (const range_const_char * a, const range_const_char * b)
{
    size_t size = range_count (*a);

    if (size != (size_t) range_count (*b))
    {
	return false;
    }

    for (size_t i = 0; i < size; i++)
    {
	if (a->begin[i] != b->begin[i])
	{
	    return false;
	}
    }

    return true;
}
