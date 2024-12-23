#include <gtest/gtest.h>
#include "best_time_to_buy_and_sell_stock.h"

TEST(Solution, test1) {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int profit = sol.maxProfit(prices);
    EXPECT_EQ(profit, 5);
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> prices = {7, 6, 4, 3, 1};

    int profit = sol.maxProfit(prices);
    EXPECT_EQ(profit, 0);
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> prices = {2, 6, 0, 5};

    int profit = sol.maxProfit(prices);
    EXPECT_EQ(profit, 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
