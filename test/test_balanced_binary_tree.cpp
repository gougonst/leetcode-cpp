#include <gtest/gtest.h>
#include "balanced_binary_tree.h"

TEST(Solution, test1) {
    Solution sol;

    TreeNode* root = new TreeNode(3, 
        new TreeNode(9), 
        new TreeNode(20, 
            new TreeNode(15), 
            new TreeNode(7)));

    EXPECT_TRUE(sol.isBalanced(root));
}

TEST(Solution, test2) {
    Solution sol;

    TreeNode* root = new TreeNode(1, 
        new TreeNode(2, 
            new TreeNode(3, 
                new TreeNode(4), 
                new TreeNode(4)), 
            new TreeNode(3)), 
        new TreeNode(2));

    EXPECT_FALSE(sol.isBalanced(root));
}

TEST(Solution, test3) {
    Solution sol;

    TreeNode* root = new TreeNode(1);

    EXPECT_TRUE(sol.isBalanced(root));
}

TEST(Solution, test4) {
    Solution sol;

    TreeNode* root = nullptr;

    EXPECT_TRUE(sol.isBalanced(root));
}

TEST(Solution, test5) {
    Solution sol;

    TreeNode* root = new TreeNode(1, 
        new TreeNode(2), 
        new TreeNode(2, 
            new TreeNode(3, 
                new TreeNode(4), 
                new TreeNode(4)), 
            new TreeNode(3)));

    EXPECT_FALSE(sol.isBalanced(root));
}

TEST(Solution, test6) {
    Solution sol;

    TreeNode* root = new TreeNode(1, 
        new TreeNode(2, 
            new TreeNode(3, 
                new TreeNode(4), 
                nullptr), 
            nullptr), 
        nullptr);

    EXPECT_FALSE(sol.isBalanced(root));
}

TEST(Solution, test7) {
    Solution sol;

    TreeNode* root = new TreeNode(1, 
        new TreeNode(2, 
            new TreeNode(4, 
                new TreeNode(8), 
                nullptr), 
            new TreeNode(5)), 
        new TreeNode(3, 
            new TreeNode(6), 
            nullptr));

    EXPECT_TRUE(sol.isBalanced(root));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
