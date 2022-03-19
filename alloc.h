#ifndef FLAT_INCLUDES
#include <stddef.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "def.h"
#endif

void _range_clear (range_void * range);

#define range_clear(range)			\
    _range_clear (  &(range).void_cast )

#define range_alloc(range, count)		\
    {									\
	(range).begin = malloc (sizeof (*(range).begin) * count);	\
	(range).end = (range).begin + count;				\
    }
/**<
   @brief Allocates the number of elements given by count within the given range
   @param range The range in which to allocate elements
   @param count The number of elements to allocate
*/

#define range_calloc(range, count)		\
    {									\
	(range).begin = calloc (count, sizeof (*(range).begin));		\
	(range).end = (range).begin + count;				\
    }
/**<
   @brief Allocates the number of elements given by count within the given range, with the newly allocated elements all set to 0
   @param range The range in which to allocate elements
   @param count The number of elements to allocate
*/

/*#define range_copy(dst, src)						\
    {									\
	size_t count = range_count(src);				\
	range_alloc(dst, count);					\
	memcpy((dst).begin, (src).begin, count * sizeof( *(dst).begin )); \
	assert(sizeof(*(dst).begin) == sizeof(*(src).begin));		\
	}*/
#define range_copy(dst,src)						\
    {									\
	size_t copy_size = range_count(src) * sizeof(*(src).begin);	\
	(dst).begin = malloc (copy_size);				\
	(dst).end = (void*)((const char*) (dst).begin + copy_size);	\
	memcpy ((dst).begin, (src).begin, copy_size);			\
    }
/**<
   @brief Copies the contents of the source array into the destination array
*/

void _range_realloc_new (range_void * range, size_t member_size);

#define range_push(target) (_range_realloc_new(&(target).void_cast, sizeof(*(target).begin)), (target).end++)
