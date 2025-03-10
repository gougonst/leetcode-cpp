#include <gtest/gtest.h>
#include "contains_duplicate.h"

TEST(Solution, test1) {
    Solution sol;
    vector<int> nums{1, 2, 3, 1};
    EXPECT_TRUE(sol.containsDuplicate1(nums));
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> nums{1, 2, 3, 4};
    EXPECT_FALSE(sol.containsDuplicate1(nums));
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> nums{1, 2, 3, 1};
    EXPECT_TRUE(sol.containsDuplicate2(nums));
}

TEST(Solution, test4) {
    Solution sol;
    vector<int> nums{1, 2, 3, 4};
    EXPECT_FALSE(sol.containsDuplicate2(nums));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
