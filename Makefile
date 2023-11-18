# -Wall -Werror -Wextra -Wunreachable-code
CFLAGS += -g -I./include -D_POSIX_C_SOURCE=200809L -std=gnu99
LDFLAGS += -L.
LDLIBS += -lcrypt
TEST_LDLIBS += -lcunit
LIB_SRC = src/*.c
LIB = build/structures.o
TEST_FILES = test/*.c
LIB_TEST_EXE = build/test_lib
DOXY = doxyfile

all: lib

lib:
	mkdir -p build include src/server/lib
	@gcc $(CFLAGS) -fpic -shared -o $(LIB) $(LIB_SRC)

doc:
	mkdir -p docs documentation
	@doxygen $(DOXY)
	@make -C documentation/latex/ -s pdf
	@mv documentation/latex/refman.pdf documentation/FileTransferService.pdf
	@$(RM) -rf documentation/latex
	@$(RM) -rf docs/

clean:
	@$(RM) -rf  documentation/*.pdf build/* peda* .gdb_history *.ini server_log.txt

#The following targets are only intended to be run by developers and maintainers.
#Not all packages utilized in these targets are guarunteed to be present on the
#host system.
test-lib: lib
	mkdir -p test
	@gcc $(CFLAGS)  $(LDFLAGS) -o $(LIB_TEST_EXE) $(TEST_SERVER_FILES) $(LIB) $(LDLIBS) $(TEST_LDLIBS)
	$(LIB_TEST_EXE)

leak-check-lib: test-lib
	valgrind $(LIB_TEST_EXE)
