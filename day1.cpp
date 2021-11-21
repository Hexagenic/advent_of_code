#include <iostream>
#include <utility>
#include "common.h"

std::pair<int, int> consume(std::istream& input) {
    int floor = 0;
    char c;
    int cellar = 0;
    int count = 0;
    while (true) {
        input.get(c);
        count++;
        if (input.eof()) {
            break;
        }
        if (c == '(') {
            floor++;
        } else if (c == ')') {
            floor--;
        }

        if (floor == -1 && cellar == 0) {
            cellar = count; 
        }
    }
    return {floor, cellar};
}

#ifdef MAIN_BLOCK
int main(int argc, char *argv[]) {
    const auto result = consume(std::cin);
    std::cout << "=== Day 1 ===\n";
    if (isPart1(argc, argv)) {
        std::cout << "Final floor: " << result.first << '\n';
    }
    else if (isPart2(argc, argv)) {
        std::cout << "Reached cellar after " << result.second << " moves\n";
    }

    std::cout << '\n';

    return 0;
}
#endif

#ifdef TEST_BLOCK
#include <sstream>

std::pair<int, int> consume(std::string&& input) {
    std::istringstream stream(input);
    return consume(stream);
}

TEST_CASE("Part 1") {
    SUBCASE( "Example 1" ) {
        REQUIRE( consume("(())").first == 0 );
        REQUIRE( consume("()()").first == 0 );
    }

    SUBCASE( "Example 2" ) {
        REQUIRE( consume("(((").first == 3 );
        REQUIRE( consume("(()(()(").first == 3 );
    }

    SUBCASE( "Example 3" ) {
        REQUIRE( consume("))(((((").first == 3 );
    }

    SUBCASE( "Example 4" ) {
        REQUIRE( consume("())").first == -1 );
        REQUIRE( consume("))(").first == -1 );
    }

    SUBCASE( "Example 5" ) {
        REQUIRE( consume(")))").first == -3 );
        REQUIRE( consume(")())())").first == -3 );
    }
}

TEST_CASE("Part 2") {
    SUBCASE( "Example 1" ) {
        REQUIRE( consume(")").second == 1 );
    }

    SUBCASE( "Example 2" ) {
        REQUIRE( consume("()())").second == 5 );
    }
}

#endif