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
	sh makedepend.sh src/range/range.makefile

# DO NOT DELETE

src/range/string_init.o: src/range/def.h src/range/string.h
src/range/streq.o: src/range/def.h src/range/string.h
src/range/strstr_string.o: src/range/string.h src/range/def.h
src/range/strchr.o: src/range/def.h src/range/string.h
src/range/strstr.o: src/range/def.h src/range/string.h
src/range/alloc.o: src/range/def.h
src/range/strdup_to_string.o: src/range/string.h src/range/def.h
src/range/atozd.o: src/range/def.h src/range/string.h
src/range/test/range.test.o: src/range/string.h src/range/def.h
src/range/test/range.test.o: src/range/alloc.h src/range/string.h
src/range/strdup.o: src/range/string.h src/range/def.h
src/range/streq_string.o: src/range/string.h src/range/def.h
src/range/path.o: src/range/def.h src/range/path.h
src/range/string_tokenize.o: src/range/def.h src/range/string.h
