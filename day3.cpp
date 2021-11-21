#include <iostream>
#include <utility>
#include "common.h"
#include <unordered_set>

using House = std::pair<int, int>;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

using VisitedHouses = std::unordered_set<House, pair_hash>;

int santaTravel(std::istream &input, bool withRobot = false)
{
    VisitedHouses visitedHouses = {{0, 0}};

    char c;

    House currentHouse = std::make_pair(0, 0);
    House alternateHouse = std::make_pair(0, 0);

    while (true)
    {
        input.get(c);
        if (input.eof())
        {
            break;
        }

        switch (c) {
            case '>':
                currentHouse.first++;
                break;
            case '<':
                currentHouse.first--;
                break;
            case '^':
                currentHouse.second++;
                break;
            case 'v':
                currentHouse.second--;
                break;
        }

        visitedHouses.insert(currentHouse);

        if (withRobot) {
            std::swap(currentHouse, alternateHouse);
        }
    }

    return visitedHouses.size();
}

#ifdef MAIN_BLOCK
int main(int argc, char *argv[])
{
    const int visitedHouses = santaTravel(std::cin, isPart2(argc, argv));
    std::cout << "=== Day 3 ===\n";
    std::cout << "Houses with at least one present: " << visitedHouses << '\n';
    std::cout << '\n';

    return 0;
}
#endif

#ifdef TEST_BLOCK

#include <sstream>

int santaTravel(std::string &&input, bool withRobot = false)
{
    std::istringstream stream(input);
    return santaTravel(stream, withRobot);
}

TEST_CASE("Part 1")
{
    SUBCASE("Example 1")
    {
        REQUIRE(santaTravel(">") == 2);
    }

    SUBCASE("Example 2")
    {
        REQUIRE(santaTravel("^>v<") == 4);
    }

    SUBCASE("Example 3")
    {
        REQUIRE(santaTravel("^v^v^v^v^v") == 2);
    }
}

TEST_CASE("Part 2")
{
    SUBCASE("Example 1")
    {
        REQUIRE(santaTravel("^v", true) == 3);
    }

    SUBCASE("Example 2")
    {
        REQUIRE(santaTravel("^>v<", true) == 3);
    }

    SUBCASE("Example 3")
    {
        REQUIRE(santaTravel("^v^v^v^v^v", true) == 11);
    }
}

#endif