#include <gtest/gtest.h>
#include "evaluate_reverse_polish_notation.h"

TEST(Solution, test1) {
    Solution sol;
    vector<string> tokens{"2", "1", "+", "3", "*"};
    EXPECT_EQ(sol.evalRPN(tokens), 9);
}

TEST(Solution, test2) {
    Solution sol;
    vector<string> tokens{"4", "13", "5", "/", "+"};
    EXPECT_EQ(sol.evalRPN(tokens), 6);
}

TEST(Solution, test3) {
    Solution sol;
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    EXPECT_EQ(sol.evalRPN(tokens), 22);
}

TEST(Solution, test4) {
    Solution sol;
    vector<string> tokens{"4"};
    EXPECT_EQ(sol.evalRPN(tokens), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
