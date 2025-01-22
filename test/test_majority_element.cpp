#include <gtest/gtest.h>
#include "majority_element.h"

TEST(Solution, test1) {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    EXPECT_EQ(sol.majorityElement(nums), 3);
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};
    EXPECT_EQ(sol.majorityElement(nums), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
