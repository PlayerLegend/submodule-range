#include <stddef.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "def.h"
#include "string.h"

bool range_string_tokenize (range_const_char * token, const char delim, range_const_char * input)
{
    if (range_is_empty (*input))
    {
	return false;
    }
    
    token->begin = input->begin;

    token->end = input->begin + range_strchr(input, delim);

    input->begin = token->end + 1;

    return true;
}
