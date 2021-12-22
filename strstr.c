#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

size_t range_strstr (const range_const_char * haystack, const range_const_char * needle)
{
    assert (haystack->begin);
    assert (needle->begin);
    
    size_t needle_size = range_count (*needle);

    if (!needle_size)
    {
	return range_count (*haystack);
    }
    
    range_const_char scan = { .begin = haystack->begin, .end = haystack->end - needle_size + 1 };

    const char * i_scan;

    size_t i;

    for_range (i_scan, scan)
    {
	i = 0;

	while (i < needle_size)
	{
	    if (i_scan[i] != needle->begin[i])
	    {
		break;
	    }

	    i++;
	}

	if (i == needle_size)
	{
	    break;
	}
    }

    if (i_scan == scan.end)
    {
	return range_count (*haystack);
    }
    else
    {
	return range_index (i_scan, scan);
    }
}
