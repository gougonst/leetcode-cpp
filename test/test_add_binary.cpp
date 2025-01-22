#include <gtest/gtest.h>
#include "add_binary.h"

TEST(Solution, test1) {
    Solution sol;
    string a = "11";
    string b = "1";
    EXPECT_EQ(sol.addBinary(a, b), "100");
}

TEST(Solution, test2) {
    Solution sol;
    string a = "1010";
    string b = "1011";
    EXPECT_EQ(sol.addBinary(a, b), "10101");
}

TEST(Solution, test3) {
    Solution sol;
    string a = "0";
    string b = "0";
    EXPECT_EQ(sol.addBinary(a, b), "0");
}

TEST(Solution, test4) {
    Solution sol;
    string a = "1";
    string b = "1";
    EXPECT_EQ(sol.addBinary(a, b), "10");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
