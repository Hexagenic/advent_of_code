#define OPENSSL_NO_DEPRECATED

#include <string>
#include "common.h"
#include <openssl/evp.h>
#include <cstdint>

EVP_MD_CTX *md5_ctx;
unsigned char *md5_digest;
unsigned int md5_digest_len;

bool isMatch(const std::string &key, int number, bool part2) {
    std::string numberStr = std::to_string(number);

    EVP_DigestInit_ex(md5_ctx, EVP_md5(), NULL);
    EVP_DigestUpdate(md5_ctx, key.c_str(), key.size());
    EVP_DigestUpdate(md5_ctx, numberStr.c_str(), numberStr.size());
    EVP_DigestFinal_ex(md5_ctx, md5_digest, &md5_digest_len);

    auto *out_u64 = (uint64_t *) md5_digest;
    return (((uint64_t) *out_u64) & (part2 ? 0xFFFFFF : 0xF0FFFF)) == 0;
}

int lowestNum(const std::string &key, bool part2) {
    md5_ctx = EVP_MD_CTX_new();
    md5_digest_len = EVP_MD_size(EVP_md5());
    md5_digest = (unsigned char *)OPENSSL_malloc(md5_digest_len);

    int found = -1;

    for (int i = 0; i < INT32_MAX; i++) {
        if (isMatch(key, i, part2)) {
            found = i;
            break;
        }
    }

    EVP_MD_CTX_free(md5_ctx);
    OPENSSL_free(md5_digest);

    return found;
}

REGISTER_SOLUTION(4, [](auto stream, auto part) {
    std::string line;
    std::getline(stream, line);
    return lowestNum(line, part == Part::second);
})

TEST_SUITE("Day 04") {
TEST_CASE("Part 1") {
    SUBCASE("Example 1") {
        REQUIRE(lowestNum("abcdef", false) == 609043);
    }

    SUBCASE("Example 2") {
        REQUIRE(lowestNum("pqrstuv", false) == 1048970);
    }
}
}
