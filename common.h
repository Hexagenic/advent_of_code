#ifndef AOC_COMMON_H
#define AOC_COMMON_H

#include <cstring>

#ifdef BUILD_TESTS
#define TEST_BLOCK
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "third-party/doctest.h"
#else
#define MAIN_BLOCK
#endif

constexpr bool isPart1(int argc, char *argv[]) {
    return argc == 1 || strcmp(argv[1], "part1") == 0;
}


constexpr bool isPart2(int argc, char *argv[]) {
    return argc >= 2 && strcmp(argv[1], "part2") == 0;
}

#endif