C_PROGRAMS += test/range
C_PROGRAMS += test/buffer
RUN_TESTS += test/range

range-tests: test/range

test/range: src/range/strstr.o
test/range: src/range/range_atozd.o
test/range: src/range/string_tokenize.o
test/range: src/range/strchr.o
test/range: src/range/string_init.o
test/range: src/range/range_streq_string.o
test/range: src/range/streq.o
test/range: src/range/alloc.o
test/range: src/range/test/range.test.o

tests: range-tests
