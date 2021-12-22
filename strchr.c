#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

size_t range_strchr (const range_const_char * haystack, char needle)
{
    const char * i;

    for_range (i, *haystack)
    {
	if (*i == needle)
	{
	    break;
	}
    }

    return range_index(i, *haystack);
}
