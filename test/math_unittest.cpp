#include "gtest/gtest.h"
#include "../src/math.hpp"

TEST(math, convert_base_number)
{
    std::string sut;

    // 10進数の基数変換を検証
    sut = convert_base_number( 0, 10);
    EXPECT_EQ(sut, "0");
    sut = convert_base_number( 11, 10);
    EXPECT_EQ(sut, "11");

    // 2進数の基数変換を検証
    sut = convert_base_number( 2, 2);
    EXPECT_EQ(sut, "10");
    sut = convert_base_number( 11, 2);
    EXPECT_EQ(sut, "1011");
}

TEST(math, factorial)
{
    int sut = factorial(3);
    EXPECT_EQ(sut, 6);
}

TEST(math, is_prime)
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