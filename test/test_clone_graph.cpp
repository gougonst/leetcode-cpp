#include "clone_graph.h"
#include <gtest/gtest.h>

TEST(Solution, test1) {
    Solution sol;
    vector<int> nums{1, 2, 3, 1};
    EXPECT_TRUE(sol.containsDuplicate1(nums));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
