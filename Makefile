days := $(patsubst %.cpp,%,$(wildcard *.cpp))
day_tests := $(patsubst %.cpp,%-test,$(wildcard *.cpp))
executables := $(patsubst %.cpp,output/%,$(wildcard *.cpp))
tests := $(patsubst %.cpp,output/%-test,$(wildcard *.cpp))

# default: Build and run all days and their tests
run-and-test: run test

run: $(days)
test: $(day_tests)
build: $(executables) $(tests)

output/%: %.cpp
	@mkdir -p output
	g++ -O3 -Wall -Wextra -Werror -Wpedantic $< -lcrypto -o $@

output/%-test: %.cpp third-party/doctest.h
	@mkdir -p output
	g++ -O3 -Wall -Wextra -Werror -Wpedantic -DBUILD_TESTS $< -lcrypto  -o $@

# Build and run specific day. Example: `make day3`
day%: output/day% input/day%.txt
	./$< part1 < $(word 2,$^)
	./$< part2 < $(word 2,$^)

day%-test: output/day%-test
	./$< -fc