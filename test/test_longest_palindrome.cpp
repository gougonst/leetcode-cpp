#include <gtest/gtest.h>
#include "longest_palindrome.h"

TEST(Solution, test1) {
    Solution sol;
    string letters = "a";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 1);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 1);
}

TEST(Solution, test2) {
    Solution sol;
    string letters = "aa";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 2);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 2);
}

TEST(Solution, test3) {
    Solution sol;
    string letters = "aab";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 3);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 3);
}

TEST(Solution, test4) {
    Solution sol;
    string letters = "aabc";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 3);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 3);
}

TEST(Solution, test5) {
    Solution sol;
    string letters = "abccccdd";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 7);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 7);
}

TEST(Solution, test6) {
    Solution sol;
    string letters = "abbccccdd";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 9);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 9);
}

TEST(Solution, test7) {
    Solution sol;
    string letters = "aabbbbcceeccdd";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 14);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 14);
}

TEST(Solution, test8) {
    Solution sol;
    string letters = "aAbbbbcceeccdd";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 13);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 13);
}

TEST(Solution, test9) {
    Solution sol;
    string letters = "aA";
    EXPECT_EQ(sol.longestPalindromeArray(letters), 1);
    EXPECT_EQ(sol.longestPalindromeSet(letters), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
