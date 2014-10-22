.phony: all test clean

all: test

test:
	gcc -o bin/test src/test.c

clean:
	rm -f bin/*
