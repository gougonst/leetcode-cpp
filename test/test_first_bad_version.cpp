#include <gtest/gtest.h>
#include "first_bad_version.h"

TEST(Solution, test1) {
    Solution sol;
    sol.setBadVersion(1);
    EXPECT_EQ(sol.firstBadVersion(5), 1);
}

TEST(Solution, test2) {
    Solution sol;
    sol.setBadVersion(5);
    EXPECT_EQ(sol.firstBadVersion(5), 5);
}

TEST(Solution, test3) {
    Solution sol;
    sol.setBadVersion(2);
    EXPECT_EQ(sol.firstBadVersion(5), 2);
}

TEST(Solution, test4) {
    Solution sol;
    sol.setBadVersion(3);
    EXPECT_EQ(sol.firstBadVersion(5), 3);
}

TEST(Solution, test5) {
    Solution sol;
    sol.setBadVersion(3);
    EXPECT_EQ(sol.firstBadVersion(6), 3);
}

TEST(Solution, test6) {
    Solution sol;
    sol.setBadVersion(4);
    EXPECT_EQ(sol.firstBadVersion(6), 4);
}

TEST(Solution, test7) {
    Solution sol;
    sol.setBadVersion(1);
    EXPECT_EQ(sol.firstBadVersion(1), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
