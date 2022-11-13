#include <iostream>
#include <utility>
#include <regex>
#include "common.h"

struct Measurements {
    int length;
    int width;
    int height;
};

std::regex pattern(R"(^(\d+)x(\d+)x(\d+)$)");

static Measurements parse(const std::string &str) {
    std::smatch match;
    if (!std::regex_match(str, match, pattern)) {
        std::cerr << "Failed to parse: " << str << "\n";
        exit(1);
    }

    const int length = std::stoi(match[1]);
    const int width = std::stoi(match[2]);
    const int height = std::stoi(match[3]);

    return {length, width, height};
}

constexpr std::pair<int, int> smallestSides(const Measurements &measurements) {
    if (measurements.length >= measurements.width && measurements.length >= measurements.height) {
        return {measurements.width, measurements.height};
    } else if (measurements.width >= measurements.length && measurements.width >= measurements.height) {
        return {measurements.length, measurements.height};
    } else {
        return {measurements.length, measurements.width};
    }
}

constexpr int paperArea(const Measurements &measurements) {
    const auto boxArea =
            (2 * measurements.length * measurements.width) + (2 * measurements.width * measurements.height) +
            (2 * measurements.height * measurements.length);
    const auto slackSides = smallestSides(measurements);
    const auto slack = slackSides.first * slackSides.second;
    return boxArea + slack;
}

constexpr int ribbonLength(const Measurements &measurements) {
    const auto sides = smallestSides(measurements);
    const int perimiter = 2 * sides.first + 2 * sides.second;
    const auto volume = measurements.length * measurements.width * measurements.height;
    return perimiter + volume;
}

bool operator==(const Measurements &a, const Measurements &b) {
    return a.height == b.height && a.width == b.width && a.height == b.height;
}

REGISTER_SOLUTION(2, [](auto stream, auto part) {
    if (part == Part::first) {
        int totalPaperArea = 0;
        for (std::string package; std::getline(stream, package);) {
            totalPaperArea += paperArea(parse(package));
        }

        return totalPaperArea;
    } else {
        int totalRibbonLength = 0;

        for (std::string package; std::getline(stream, package);) {
            totalRibbonLength += ribbonLength(parse(package));
        }

        return totalRibbonLength;
    }
})

std::ostream &operator<<(std::ostream &os, const Measurements &m) {
    os << "Measurement(" << m.length << ", " << m.width << ", " << m.height << ")";
    return os;
}

TEST_SUITE("Day 2") {
TEST_CASE("Part 1") {
    SUBCASE("Example 1") {
        REQUIRE(paperArea({2, 3, 4}) == 58);
        REQUIRE(smallestSides({2, 3, 4}) == std::make_pair(2, 3));
    }

    SUBCASE("Example 2") {
        REQUIRE(paperArea({1, 1, 10}) == 43);
        REQUIRE(smallestSides({1, 1, 10}) == std::make_pair(1, 1));
    }

    SUBCASE("Parse") {
        REQUIRE(parse("1x2x3") == Measurements{1, 2, 3});
    }

    SUBCASE("Slack") {
        REQUIRE(smallestSides({1, 2, 3}) == std::make_pair(1, 2));
        REQUIRE(smallestSides({4, 5, 3}) == std::make_pair(4, 3));
    }
}

TEST_CASE("Part 2") {
    SUBCASE("Example 1") {
        REQUIRE(ribbonLength({2, 3, 4}) == 34);
    }
    SUBCASE("Example 2") {
        REQUIRE(ribbonLength({1, 1, 10}) == 14);
    }
}
}
