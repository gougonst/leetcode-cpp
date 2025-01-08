#include <gtest/gtest.h>
#include "climbing_stairs.h"

TEST(Solution, test1) {
    Solution sol;
    EXPECT_EQ(sol.climbStairs(2), 2);
}

TEST(Solution, test2) {
    Solution sol;
    EXPECT_EQ(sol.climbStairs(3), 3);
}

TEST(Solution, test3) {
    Solution sol;
    EXPECT_EQ(sol.climbStairs(1), 1);
}

TEST(Solution, test4) {
    Solution sol;
    EXPECT_EQ(sol.climbStairs(4), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
