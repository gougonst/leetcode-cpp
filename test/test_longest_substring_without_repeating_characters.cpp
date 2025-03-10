#include <gtest/gtest.h>
#include "longest_substring_without_repeating_characters.h"

TEST(Solution, test1) {
    Solution sol;
    string s = "abcabcbb";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 3);
}

TEST(Solution, test2) {
    Solution sol;
    string s = "";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 0);
}

TEST(Solution, test3) {
    Solution sol;
    string s = "bbbbbbb";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 1);
}

TEST(Solution, test4) {
    Solution sol;
    string s = "b";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 1);
}

TEST(Solution, test5) {
    Solution sol;
    string s = "bbbbabbbbb";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 2);
}

TEST(Solution, test6) {
    Solution sol;
    string s = "abcdcdbae";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 5);
}

TEST(Solution, test7) {
    Solution sol;
    string s = "tmmzuxt";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
