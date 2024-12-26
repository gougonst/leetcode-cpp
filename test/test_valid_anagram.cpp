#include <gtest/gtest.h>
#include "valid_anagram.h"

TEST(Solution, test1) {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    EXPECT_TRUE(sol.isAnagram(s, t));
}

TEST(Solution, test2) {
    Solution sol;
    string s = "rat";
    string t = "car";
    EXPECT_FALSE(sol.isAnagram(s, t));
}

TEST(Solution, test3) {
    Solution sol;
    string s = "";
    string t = "";
    EXPECT_TRUE(sol.isAnagram(s, t));
}

TEST(Solution, test4) {
    Solution sol;
    string s = "a";
    string t = "a";
    EXPECT_TRUE(sol.isAnagram(s, t));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
