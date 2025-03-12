#include "coin_change.h"
#include <gtest/gtest.h>

TEST(Solution, test1) {
    Solution sol;
    vector<int> coins{1, 2, 5};
    int amount = 11;
    EXPECT_EQ(sol.coinChange1(coins, amount), 3);
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> coins{2};
    int amount = 3;
    EXPECT_EQ(sol.coinChange1(coins, amount), -1);
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> coins{1};
    int amount = 0;
    EXPECT_EQ(sol.coinChange1(coins, amount), 0);
}

TEST(Solution, test4) {
    Solution sol;
    vector<int> coins{1, 2, 5};
    int amount = 11;
    EXPECT_EQ(sol.coinChange2(coins, amount), 3);
}

TEST(Solution, test5) {
    Solution sol;
    vector<int> coins{2};
    int amount = 3;
    EXPECT_EQ(sol.coinChange2(coins, amount), -1);
}

TEST(Solution, test6) {
    Solution sol;
    vector<int> coins{1};
    int amount = 0;
    EXPECT_EQ(sol.coinChange2(coins, amount), 0);
}

TEST(Solution, test7) {
    Solution sol;
    vector<int> coins{1, 2, 5};
    int amount = 11;
    EXPECT_EQ(sol.coinChange3(coins, amount), 3);
}

TEST(Solution, test8) {
    Solution sol;
    vector<int> coins{2};
    int amount = 3;
    EXPECT_EQ(sol.coinChange3(coins, amount), -1);
}

TEST(Solution, test9) {
    Solution sol;
    vector<int> coins{1};
    int amount = 0;
    EXPECT_EQ(sol.coinChange3(coins, amount), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
