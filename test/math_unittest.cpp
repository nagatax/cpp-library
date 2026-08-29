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

namespace {
double square(double x)
{
    return x * x;
}

double cube(double x)
{
    return x * x * x;
}
}

TEST(math, differentiate)
{
    // f(x) = x^2 の x = 3 における微分係数は 6
    EXPECT_NEAR(differentiate(square, 3.0), 6.0, 1e-6);

    // f(x) = x^3 の x = 2 における微分係数は 12
    EXPECT_NEAR(differentiate(cube, 2.0), 12.0, 1e-6);

    // 定数関数の微分係数は 0
    EXPECT_NEAR(differentiate([](double) { return 5.0; }, 1.0), 0.0, 1e-6);
}

TEST(math, differentiate_second)
{
    // f(x) = x^2 の2階微分係数は 2
    EXPECT_NEAR(differentiate_second(square, 3.0), 2.0, 1e-4);

    // f(x) = x^3 の x = 2 における2階微分係数は 12
    EXPECT_NEAR(differentiate_second(cube, 2.0), 12.0, 1e-4);
}

TEST(math, factorial)
{
    int sut = factorial(3);
    EXPECT_EQ(sut, 6);
}

TEST(math, get_random_number)
{
    unsigned int seed = time(NULL);
    unsigned int number = 10;
    int sut = get_random_number(seed, number);

    srand(seed);
    EXPECT_EQ(sut, rand() % (number + 1));
}

TEST(math, is_prime)
{
    bool sut;

    // 2は素数
    sut = is_prime(2);
    EXPECT_EQ(sut, true);

    // 3は素数
    sut = is_prime(3);
    EXPECT_EQ(sut, true);

    // 13は素数
    sut = is_prime(13);
    EXPECT_EQ(sut, true);

    // 4は素数でない(2で割り切れる)
    sut = is_prime(4);
    EXPECT_EQ(sut, false);

    // 39は素数でない(3で割り切れる)
    sut = is_prime(39);
    EXPECT_EQ(sut, false);
}

TEST(math, is_leap)
{
    bool sut;

    // 2000年はうるう年
    sut = is_leap(2000);
    EXPECT_EQ(sut, true);

    // 2001年はうるう年でない
    sut = is_leap(2001);
    EXPECT_EQ(sut, false);

    // 2100年はうるう年でない
    sut = is_leap(2100);
    EXPECT_EQ(sut, false);
}