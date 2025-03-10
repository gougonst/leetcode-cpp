#include <gtest/gtest.h>
#include "01_matrix.h"

TEST(Solution, test1) {
    Solution sol;
    vector<vector<int>> arr{{0, 0, 0},
                            {0, 1, 0},
                            {0, 0, 0}};
    vector<vector<int>> expect{{0, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0}};
    EXPECT_EQ(sol.updateMatrix(arr), expect);
}

TEST(Solution, test2) {
    Solution sol;
    vector<vector<int>> arr{{0, 0, 0},
                            {0, 1, 0},
                            {1, 1, 1}};
    vector<vector<int>> expect{{0, 0, 0},
                               {0, 1, 0},
                               {1, 2, 1}};
    EXPECT_EQ(sol.updateMatrix(arr), expect);
}

TEST(Solution, test3) {
    Solution sol;
    vector<vector<int>> arr{{0, 0, 0, 0, 1},
                            {0, 1, 0, 0, 0},
                            {1, 1, 1, 1, 0},
                            {0, 1, 1, 0, 0},
                            {1, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0}};
    vector<vector<int>> expect{{0, 0, 0, 0, 1},
                               {0, 1, 0, 0, 0},
                               {1, 2, 1, 1, 0},
                               {0, 1, 1, 0, 0},
                               {1, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0}};
    EXPECT_EQ(sol.updateMatrix(arr), expect);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
