#include <gtest/gtest.h>
#include "two_sum.h"

TEST(Solution, test1) {
    Solution sol;
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> expected = {0, 1};
    EXPECT_EQ(sol.twoSum(arr, target), expected);
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> arr = {3, 2, 4};
    int target = 6;
    vector<int> expected = {1, 2};
    EXPECT_EQ(sol.twoSum(arr, target), expected);
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> arr = {3, 3};
    int target = 6;
    vector<int> expected = {0, 1};
    EXPECT_EQ(sol.twoSum(arr, target), expected);
}

TEST(Solution, test4) {
    Solution sol;
    vector<int> arr = {3, 3};
    int target = 4;
    vector<int> expected = {};
    EXPECT_EQ(sol.twoSum(arr, target), expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
