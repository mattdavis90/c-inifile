.phony: all test valgrind clean

all: test

test:
	gcc -o bin/test src/test.c

valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -v bin/test sample

clean:
	rm -f bin/*
