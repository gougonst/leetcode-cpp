#include "course_schedule.h"
#include <gtest/gtest.h>

TEST(Solution, test1) {
    Solution sol;
    vector<vector<int>> prerequisites{{1, 0}};
    EXPECT_TRUE(sol.canFinish(2, prerequisites));
}

TEST(Solution, test2) {
    Solution sol;
    vector<vector<int>> prerequisites{{1, 0},
                                      {0, 1}};
    EXPECT_FALSE(sol.canFinish(2, prerequisites));
}

TEST(Solution, test3) {
    Solution sol;
    vector<vector<int>> prerequisites{{1, 2},
                                      {1, 3},
                                      {0, 1},
                                      {5, 3},
                                      {4, 5}};
    EXPECT_TRUE(sol.canFinish(6, prerequisites));
}

TEST(Solution, test4) {
    Solution sol;
    vector<vector<int>> prerequisites{{1, 2},
                                      {1, 3},
                                      {0, 1},
                                      {3, 5},
                                      {4, 5},
                                      {4, 1}};
    EXPECT_FALSE(sol.canFinish(6, prerequisites));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
