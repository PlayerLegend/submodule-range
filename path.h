#ifndef FLAT_INCLUDES
#include <stddef.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "def.h"
#endif

/**
   @file range/path.h
   Provides functionality for working with paths using the range_char type described in range/def.h
*/

void range_dirname (range_const_char * path, char sep);
/**<
   @brief Given a range that contains a path, this function will modify that range so that it contains only the dirname portion of that path.
   @param path The path to modify
   @param sep The path separator character
 */

void range_basename (range_const_char * path, char sep);
/**<
   @brief Given a range that contains a path, this function will modify that range so that it contains only the basename portion of that path.
   @param path The path to modify
   @param sep The path separator character
*/
