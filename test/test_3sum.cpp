#include <gtest/gtest.h>
#include <vector>
#include "3sum.h"
using namespace std;

bool arrayEqual2d(const vector<vector<int>> &arr1, const vector<vector<int>> &arr2) {
    if (arr1.size() != arr2.size())
        return false;

    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i].size() != arr2[i].size())
            return false;

        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
}

TEST(Solution, test1) {
    Solution sol;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    EXPECT_TRUE(arrayEqual2d(sol.threeSum(nums), {{-1, -1, 2}, {-1, 0, 1}}));
}

TEST(Solution, test2) {
    Solution sol;
    vector<int> nums{0, 1, 1};
    EXPECT_TRUE(arrayEqual2d(sol.threeSum(nums), {}));
}

TEST(Solution, test3) {
    Solution sol;
    vector<int> nums{0, 0, 0};
    EXPECT_TRUE(arrayEqual2d(sol.threeSum(nums), {{0, 0, 0}}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
