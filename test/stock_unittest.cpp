#include "gtest/gtest.h"
extern "C" {
#include "stock.h"
}

TEST(StockTest, ParsePrice) {
    const char *json = "{\"regularMarketPrice\": 123.45}";
    double price = parse_stock_price(json);
    EXPECT_NEAR(price, 123.45, 1e-6);
}

