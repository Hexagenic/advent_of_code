#include <iostream>
#include <utility>
#include "common.h"
#include <openssl/md5.h>
#include <cstdint>

bool isMatch(const std::string &key, int number, bool part2)
{
    MD5_CTX c;
    unsigned char out[MD5_DIGEST_LENGTH];
    MD5_Init(&c);
    MD5_Update(&c, key.c_str(), key.size());
    std::string numberStr = std::to_string(number);
    MD5_Update(&c, numberStr.c_str(), numberStr.size());
    MD5_Final(out, &c);

    uint64_t* out_u64 = (uint64_t*)out;
    return (((uint64_t) *out_u64) & (part2 ? 0xFFFFFF : 0xF0FFFF) ) == 0;
}

int lowestNum(const std::string &key, bool part2)
{
    for (int i = 0; i < INT32_MAX; i++)
    {
        if (isMatch(key, i, part2))
        {
            return i;
        }
    }

    return -1;
}

#ifdef MAIN_BLOCK
int main(int argc, char *argv[])
{
    std::cout << "=== Day 4 ===\n";
    for (std::string line; std::getline(std::cin, line);)
    {
        std::cout << lowestNum(line, isPart2(argc, argv)) << '\n';
    }
    std::cout << '\n';

    return 0;
}
#endif

#ifdef TEST_BLOCK
TEST_CASE("Part 1")
{
    SUBCASE("Example 1")
    {
        REQUIRE(lowestNum("abcdef", false) == 609043);
    }

    SUBCASE("Example 2")
    {
        REQUIRE(lowestNum("pqrstuv", false) == 1048970);
    }
}

#endif