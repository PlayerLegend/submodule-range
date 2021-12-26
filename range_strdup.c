#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

void range_strdup (range_char * result, range_const_char * input)
{
    size_t input_size = range_count(*input);

    result->begin = malloc (input_size) + 1;

    if (!result->begin)
    {
	perror ("malloc");
	exit(1);
    }

    result->end = result->begin + input_size;

    memcpy (result->begin, input->begin, input_size);

    *result->end = '\0';
}
