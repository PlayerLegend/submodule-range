#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

char * range_strdup_to_string (const range_const_char * input)
{
    size_t input_size = range_count(*input);
    char * retval = malloc (input_size + 1);

    memcpy (retval, input->begin, input_size);
    retval[input_size] = '\0';

    return retval;
}
