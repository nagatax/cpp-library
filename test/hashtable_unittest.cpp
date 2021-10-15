#include "gtest/gtest.h"
#include "../src/hashtable.hpp"

TEST(hashtable_test, init_hash) {

    Hash h;
    bool sut = init_hash(&h, 1);

    ASSERT_TRUE(sut);
    EXPECT_EQ(h.size, 1);
}

TEST(hashtable_test, hash) {

    int sut = hash(15, 10);
    EXPECT_EQ(sut, 5);

    sut = hash(10, 10);
    EXPECT_EQ(sut, 0);
}

TEST(hashtable_test, free_hash) {

    Hash h;

    init_hash(&h, 1);

    bool sut = init_hash(&h, 1);
    EXPECT_TRUE(sut);
    EXPECT_EQ(h.size, 1);
    EXPECT_EQ(NULL, h.table[0]);

    free_hash(&h);
//    EXPECT_EQ(NULL, h.table);
}