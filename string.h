#ifndef FLAT_INCLUDES
#include <stddef.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "def.h"
#endif

/**
   @file range/string.h
   Provides functionality for working with strings using the range_char type described in range/def.h
*/

size_t range_strstr (const range_const_char * haystack, const range_const_char * needle);
/**<
   @brief This function is similar to strstr, but works on ranges instead of null terminated strings. It will search haystack for needle, and returns the offset of needle within haystack if needle is found. If needle is not found, it returns the width of haystack.
   @param haystack The string range to search
   @param needle The search query to match in haystack
*/

size_t range_strchr (const range_const_char * haystack, char needle);
/**<
   @brief This function is similar to strchr, but works on ranges instead of null terminated strings. It will search haystack for needle, and returns the offset of needle within haystack if needle is found. If needle is not found, it returns the width of haystack.
   @param haystack The string range to search
   @param needle The search query to match in haystack
*/

bool range_streq (const range_const_char * a, const range_const_char * b);
/**<
   @brief Returns true if the range strings a and b match or false if they do not.
*/

bool range_streq_string (const range_const_char * a, const char * b);
/**<
   @brief Works like range_streq, except that one parameter is a null terminated string.
*/

size_t range_atozd (size_t * restrict output, const range_const_char * restrict input);
/**<
   @brief Works like atozd, but instead of a null terminated string, this function uses a range string
   @param output The resulting integer
   @param input The input string to parse
*/

size_t range_strstr_string (const range_const_char * haystack, const char * needle);
/**<
   @brief Works like range_strstr, except that the search query is a null terminated string instead of a range string
 */

char * range_strdup_to_string (const range_const_char * input);
/**<
   @brief Copies the given range string into a new null terminated string
*/

void range_strdup (range_char * result, range_const_char * input);
/**<
   Copies the given range string into a new range string
   @param result The new string to be allocated
   @param input The reference string to copy
*/

void range_string_init (range_const_char * target, const char * input);
/**<
   Initializes a range string from a null terminated string
*/

bool range_string_tokenize (range_const_char * token, const char delim, range_const_char * input);
/**<
   Iterates through tokens in the input. The begin pointer of the input string will be moved forward by this function.
   @param token The resulting token
   @param delim The delimiter to use
   @param input The input string
   @return True if a new token was found, false if input is exhausted
*/
