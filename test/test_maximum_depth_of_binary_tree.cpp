#include <gtest/gtest.h>
#include "maximum_depth_of_binary_tree.h"

TEST(Solution, test1) {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    EXPECT_EQ(sol.maxDepth(root), 3);
}

TEST(Solution, test2) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    EXPECT_EQ(sol.maxDepth(root), 2);
}

TEST(Solution, test3) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(sol.maxDepth(root), 1);
}

TEST(Solution, test4) {
    Solution sol;
    EXPECT_EQ(sol.maxDepth(nullptr), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
