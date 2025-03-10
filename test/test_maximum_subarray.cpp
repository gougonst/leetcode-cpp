#include <gtest/gtest.h>
#include "maximum_subarray.h"

TEST(Solution, test1) {
    Solution sol;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(sol.maxSubArray(nums), 6);
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> nums{1};
    EXPECT_EQ(sol.maxSubArray(nums), 1);
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> nums{5, 4, -1, 7, 8};
    EXPECT_EQ(sol.maxSubArray(nums), 23);
}

TEST(Solution, test4) {
    Solution sol;
    vector<int> nums{-2, -1};
    EXPECT_EQ(sol.maxSubArray(nums), -1);
}

TEST(Solution, test5) {
    Solution sol;
    vector<int> nums{-2, -1, 1};
    EXPECT_EQ(sol.maxSubArray(nums), 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
