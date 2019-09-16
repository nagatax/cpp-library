#include "gtest/gtest.h"
#include "../src/array.h"

TEST(array_test, func_ary_reverse) {

    int a[5] = {1, 2, 3, 4, 5};
    int len = sizeof(a) / sizeof(a[0]);
    int expect[5] = {5, 4, 3, 2, 1};

    ary_reverse(a, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(expect[i], a[i]);
    }
}