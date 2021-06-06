#include "gtest/gtest.h"
#include "../src/is_prime.hpp"

TEST(is_prime, is_prime)
{
    bool sut;

    // 2進数の基数変換を検証
    // 13は素数
    sut = is_prime(13);
    EXPECT_EQ(sut, true);

    // 4は素数でない(2で割り切れる)
    sut = is_prime(4);
    EXPECT_EQ(sut, false);
}