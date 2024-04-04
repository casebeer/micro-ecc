
CC = gcc

LIB := bin/static/libuECC.a
OFILES := bin/static/uECC.o

TEST_SRCS = $(wildcard test/*.c)
TEST_BINARIES = $(addprefix bin/,$(TEST_SRCS:.c=))
TEST_OBJS = $(addprefix bin/,$(TEST_SRCS:.c=.o))

tests: $(LIB) $(TEST_BINARIES)

test: $(LIB) $(TEST_BINARIES)
	@#set -e ; 
	for bin in $(TEST_BINARIES); do $${bin} ; done

bin/static/%.o: %.c
	mkdir -p "$(dir $@)"
	gcc -c -I./ $< -o $@

bin/test/%.o: test/%.c
	mkdir -p "$(dir $@)"
	gcc -c -I./ $< -o $@

%.o :: %.c
	mkdir -p "$(dir $@)"
	gcc -c -I./ $< -o $@

$(LIB) : $(OFILES)
	mkdir -p "$(dir $@)"
	ar rs $@ $?

bin/test/% : bin/test/%.o
	mkdir -p "$(dir $@)"
	gcc $< -Lbin/static -luECC -o $@

clean:
	rm -f $(TEST_BINARIES) $(TEST_OBJS) $(OFILES) $(LIB)

lib: $(LIB)

.PHONY : clean lib tests test
