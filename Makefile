all: test

build:
	@mkdir -p build/

test: tests/test.c dyn_array.h | build
	gcc -o build/$@ $< -Wall -Werror -Wextra -std=c99 -pedantic -ggdb -I.

clean:
	rm -rf build

.PHONY: clean
