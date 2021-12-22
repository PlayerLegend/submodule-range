#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "def.h"
#include "path.h"

void range_dirname (range_const_char * path, char sep)
{
    path->end--;

    while (path->end >= path->begin && *path->end == sep)
    {
	path->end--;
    }
    
    while (path->end >= path->begin && *path->end != sep)
    {
	path->end--;
    }

    while (path->end >= path->begin && *path->end == sep)
    {
	path->end--;
    }

    path->end++;

    assert (path->end >= path->begin);
}

void range_basename (range_const_char * path, char sep)
{
    const char * previous_sep = path->begin;
    
    while (path->begin < path->end)
    {
	if (*path->begin == sep)
	{
	    previous_sep = path->begin;
	}
	
	path->begin++;
    }

    path->begin = previous_sep;

    if (!range_is_empty (*path))
    {
	if (*path->begin == sep)
	{
	    path->begin++;
	}
    }

    assert (path->begin <= path->end);
}
