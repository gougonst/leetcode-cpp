#include <gtest/gtest.h>
#include "flood_fill.h"

TEST(Solution, test1) {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1}, 
        {1, 1, 0}, 
        {1, 0, 1}
    };
    vector<vector<int>> expectedImage = {
        {2, 2, 2}, 
        {2, 2, 0}, 
        {2, 0, 1}
    };
    EXPECT_EQ(sol.floodFill(image, 1, 1, 2), expectedImage);
}

TEST(Solution, test2) {
    Solution sol;
    vector<vector<int>> image = {
        {0, 0, 0}, 
        {0, 0, 0}
    };
    vector<vector<int>> expectedImage = {
        {0, 0, 0}, 
        {0, 0, 0}
    };
    EXPECT_EQ(sol.floodFill(image, 0, 0, 0), expectedImage);
}

TEST(Solution, test3) {
    Solution sol;
    vector<vector<int>> image = {
        {0}, 
        {1}, 
        {1}, 
        {0}
    };
    vector<vector<int>> expectedImage = {
        {0}, 
        {2}, 
        {2}, 
        {0}
    };
    EXPECT_EQ(sol.floodFill(image, 2, 0, 2), expectedImage);
}

TEST(Solution, test4) {
    Solution sol;
    vector<vector<int>> image = {
        {0, 1, 1, 0}
    };
    vector<vector<int>> expectedImage = {
        {0, 2, 2, 0}
    };
    EXPECT_EQ(sol.floodFill(image, 0, 2, 2), expectedImage);
}

TEST(Solution, test5) {
    Solution sol;
    vector<vector<int>> image = {
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    };
    vector<vector<int>> expectedImage = {
        {1, 1, 1}, 
        {1, 1, 1}, 
        {1, 1, 1}
    };
    EXPECT_EQ(sol.floodFill(image, 1, 1, 1), expectedImage);
}

TEST(Solution, test6) {
    Solution sol;
    vector<vector<int>> image = {
        {0}
    };
    vector<vector<int>> expectedImage = {
        {1}
    };
    EXPECT_EQ(sol.floodFill(image, 0, 0, 1), expectedImage);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
