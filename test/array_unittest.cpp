#include "gtest/gtest.h"
#include "../src/array.hpp"

TEST(array_test, func_ary_reverse) {

    int a[5] = {1, 2, 3, 4, 5};
    int len = sizeof(a) / sizeof(a[0]);
    int expect[5] = {5, 4, 3, 2, 1};

    ary_reverse(a, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(expect[i], a[i]);
    }
}

TEST(array_test, search) {

    // 番兵用の要素を末尾に追加し領域を確保する
    int x[] = {1, 3, 5, 7, 9, 0};
    int nx = sizeof(x) / sizeof(x[0]);
    int sut = 0;

    sut = search(x, nx, 5);
    EXPECT_EQ(sut, 2);

    sut = search(x, nx, 99);
    EXPECT_EQ(sut, -1);
}