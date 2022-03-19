#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#define FLAT_INCLUDES
#include "../def.h"
#include "../alloc.h"
#include "../string.h"

range_typedef(int,test);

void setup_string (range_const_char * output, char mem[], const char * input)
{
    strcpy (mem, input);

    output->begin = mem;
    output->end = mem + strlen (mem);
}

void test_range_atozd()
{
    char mem[128];

    range_const_char string;

    setup_string (&string, mem, "1234asdf");

    size_t number;

    assert (4 == range_atozd (&number, &string));

    assert (number == 1234);
}

void test_range_strstr ()
{
    range_const_char string1, string2;

    char mem1[128], mem2[128];

    setup_string (&string1, mem1, "asdfbcle");
    setup_string (&string2, mem2, "asdf");

    assert (0 == range_strstr(&string1, &string2));

    setup_string (&string2, mem2, "bcle");

    assert (4 == range_strstr(&string1, &string2));
    
    setup_string (&string2, mem2, "1234");

    assert (8 == range_strstr(&string1, &string2));
}

void test_string_tokenize()
{
    range_const_char string;
    range_string_init(&string, "asdf.bcle.1234...45273");

    range_const_char token;

    assert (range_string_tokenize(&token, '.', &string));
    assert (range_streq_string(&token, "asdf"));
    
    assert (range_string_tokenize(&token, '.', &string));
    assert (range_streq_string(&token, "bcle"));
    
    assert (range_string_tokenize(&token, '.', &string));
    assert (range_streq_string(&token, "1234"));
    
    assert (range_string_tokenize(&token, '.', &string));
    assert (range_streq_string(&token, ""));
    
    assert (range_string_tokenize(&token, '.', &string));
    assert (range_streq_string(&token, ""));
    
    assert (range_string_tokenize(&token, '.', &string));
    assert (range_streq_string(&token, "45273"));
    
    assert (!range_string_tokenize(&token, '.', &string));
}

void test_range_copy()
{
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9 };

    range_typedef(int, int);

    range_int src = { .begin = array, .end = array + sizeof(array) / sizeof(array[0]) };

    range_int dst = {0};

    range_copy (dst, src);

    assert (src.begin != dst.begin);
    
    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
	assert (src.begin[i] == dst.begin[i]);
    }

    range_clear (dst);
}

void test_range_push()
{
    range_typedef(int,int);

    range_int target = {0};
    
    for (int i = 0; i < 100; i++)
    {
	*range_push(target) = i;
    }

    for (int i = 0; i < 100; i++)
    {
	int * member = target.begin + i;

	assert (member < target.end);

	assert (*member == i);
    }

    range_clear (target);
}

int main (int argc, char * argv[])
{
    range_test range = {0};
    assert (range_count (range) == 0);
    assert (range_is_empty (range));

    int range_body[5];
    range.begin = range_body;
    range.end = range_body + 5;

    assert (range_count (range) == 5);
    assert (!range_is_empty (range));
    assert (range_count (range.const_cast) == range_count(range));

    for (int i = 0; i < 5; i++)
    {
	int set = 5 - i;
	printf ("set element %d: %d\n", i, set);
	range_body [i] = set;
    }

    int * element;
    
    for_range (element, range)
    {
	printf ("element %zd: %d\n", (ssize_t)(element - range.begin), *element);
    }

    test_range_strstr();

    test_range_atozd();

    test_string_tokenize();

    test_range_copy ();

    test_range_push();

    return 0;
}
