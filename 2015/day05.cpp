#include "common.h"
#include <iostream>
#include <sstream>
#include <utility>

namespace {

bool isNice(const std::string &line) {
  int vowelCount = 0;
  char previous = '\0';
  bool hasDouble = false;

  for (int i = 0; i < line.length(); i++) {
    char c = line[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowelCount++;
    }

    if (c == previous) {
      hasDouble = true;
    }

    if (c == 'b' && previous == 'a') {
      return false;
    } else if (c == 'd' && previous == 'c') {
      return false;
    } else if (c == 'q' && previous == 'p') {
      return false;
    } else if (c == 'y' && previous == 'x') {
      return false;
    }

    previous = c;
  }

  return vowelCount >= 3 && hasDouble;
}

} // namespace

REGISTER_SOLUTION(5, [](std::istream &stream, Part part) {
  if (part == Part::second) {
    return -1;
  }

  std::string line;
  int niceCount = 0;
  std::getline(stream, line);
  while (line.length() > 0) {
    if (isNice(line)) {
      niceCount++;
    }
    std::getline(stream, line);
  }

  return niceCount;
})

TEST_SUITE("Day 01") {
  TEST_CASE("Part 1") {
    SUBCASE("Example 1") {
      CHECK(isNice("ugknbfddgicrmopn"));
      CHECK(isNice("aaa"));
      CHECK(!isNice("jchzalrnumimnmhp"));
      CHECK(!isNice("haegwjzuvuyypxyu"));
      CHECK(!isNice("dvszwmarrgswjxmb"));
    }
  }
}
