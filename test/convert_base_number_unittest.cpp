#include "gtest/gtest.h"
#include "../src/convert_base_number.hpp"

TEST(convert_base_number, convert_base_number)
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