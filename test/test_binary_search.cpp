#include <gtest/gtest.h>
#include "binary_search.h"

TEST(Solution, test1) {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    EXPECT_EQ(sol.search(nums, target), 4);
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;
    EXPECT_EQ(sol.search(nums, target), -1);
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> nums = {};
    int target = 2;
    EXPECT_EQ(sol.search(nums, target), -1);
}

TEST(Solution, test4) {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 3;
    EXPECT_EQ(sol.search(nums, target), 2);
}

TEST(Solution, test5) {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 5;
    EXPECT_EQ(sol.search(nums, target), 3);
}

TEST(Solution, test6) {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12, 19};
    int target = 5;
    EXPECT_EQ(sol.search(nums, target), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
