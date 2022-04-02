C_PROGRAMS += test/range
C_PROGRAMS += test/buffer

range-tests: test/range

test/range: src/range/strstr.o
test/range: src/range/atozd.o
test/range: src/range/string_tokenize.o
test/range: src/range/strchr.o
test/range: src/range/string_init.o
test/range: src/range/streq_string.o
test/range: src/range/streq.o
test/range: src/range/alloc.o
test/range: src/range/test/range.test.o

tests: range-tests

run-tests: run-range-tests
run-range-tests:
	sh run-tests.sh test/range

depend: range-depend
range-depend:
	cdeps src/range > src/range/depends.makefile
