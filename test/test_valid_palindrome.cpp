#include <gtest/gtest.h>
#include "valid_palindrome.h"

TEST(Solution, test1) {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    EXPECT_TRUE(sol.isPalindrome(s));
}

TEST(Solution, test2) {
    Solution sol;
    string s = "race a car";
    EXPECT_FALSE(sol.isPalindrome(s));
}

TEST(Solution, test3) {
    Solution sol;
    string s = " ";
    EXPECT_TRUE(sol.isPalindrome(s));
}

TEST(Solution, test4) {
    Solution sol;
    string s = " aa";
    EXPECT_TRUE(sol.isPalindrome(s));
}

TEST(Solution, test5) {
    Solution sol;
    string s = "aba ";
    EXPECT_TRUE(sol.isPalindrome(s));
}

TEST(Solution, test6) {
    Solution sol;
    string s = ".,";
    EXPECT_TRUE(sol.isPalindrome(s));
}

TEST(Solution, test7) {
    Solution sol;
    string s = "0P";
    EXPECT_FALSE(sol.isPalindrome(s));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
