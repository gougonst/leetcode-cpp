#include <gtest/gtest.h>
#include <stdio.h>
#include "insert_interval.h"

void print2dArray(vector<vector<int>> arr) {
    for (auto& subArr: arr) {
        for (auto& c: subArr) {
            cout << c << " ";
        }
        cout << endl;
    }
}

bool isSame2dArray(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    print2dArray(arr1);
    cout << endl;
    print2dArray(arr2);
    if (arr1.size() != arr2.size()) {
        return false;
    }

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> subArr1 = arr1[i];
        vector<int> subArr2 = arr2[i];
        if (subArr1.size() != subArr2.size()) {
            return false;
        }
        for (int j = 0; j < subArr1.size(); j++) {
            if (subArr1[j] != subArr2[j]) {
                return false;
            }
        }
    }
    return true;
}

TEST(Solution, test1) {
    Solution sol;
    vector<vector<int>> intervals{{1, 3},
                                  {6, 9}};
    vector<int> newInterval{2, 5};
    vector<vector<int>> expect{{1, 5},
                               {6, 9}};
    EXPECT_TRUE(isSame2dArray(sol.insert(intervals, newInterval), expect));
}

TEST(Solution, test2) {
    Solution sol;
    vector<vector<int>> intervals{{1, 2},
                                  {3, 5},
                                  {6, 7},
                                  {8, 10},
                                  {12, 16}};
    vector<int> newInterval{4, 8};
    vector<vector<int>> expect{{1, 2},
                               {3, 10},
                               {12, 16}};
    EXPECT_TRUE(isSame2dArray(sol.insert(intervals, newInterval), expect));
}

TEST(Solution, test3) {
    Solution sol;
    vector<vector<int>> intervals{{6, 7},
                                  {8, 10},
                                  {12, 16}};
    vector<int> newInterval{1, 3};
    vector<vector<int>> expect{{1, 3},
                               {6, 7},
                               {8, 10},
                               {12, 16}};
    EXPECT_TRUE(isSame2dArray(sol.insert(intervals, newInterval), expect));
}

TEST(Solution, test4) {
    Solution sol;
    vector<vector<int>> intervals{{6, 7},
                                  {8, 10},
                                  {12, 16}};
    vector<int> newInterval{17, 20};
    vector<vector<int>> expect{{6, 7},
                               {8, 10},
                               {12, 16},
                               {17, 20}};
    EXPECT_TRUE(isSame2dArray(sol.insert(intervals, newInterval), expect));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
