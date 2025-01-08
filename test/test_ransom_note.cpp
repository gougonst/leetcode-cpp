#include <gtest/gtest.h>
#include "ransom_note.h"

TEST(Solution, test1) {
    Solution sol;
    string ransomNote = "a";
    string magazine = "b";
    EXPECT_FALSE(sol.canConstruct(ransomNote, magazine));
}

TEST(Solution, test2) {
    Solution sol;
    string ransomNote = "aa";
    string magazine = "bb";
    EXPECT_FALSE(sol.canConstruct(ransomNote, magazine));
}

TEST(Solution, test3) {
    Solution sol;
    string ransomNote = "aa";
    string magazine = "aab";
    EXPECT_TRUE(sol.canConstruct(ransomNote, magazine));
}

TEST(Solution, test4) {
    Solution sol;
    string ransomNote = "agba";
    string magazine = "awgccba";
    EXPECT_TRUE(sol.canConstruct(ransomNote, magazine));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
