#include <gtest/gtest.h>
#include "diameter_of_binary_tree.h"

TEST(Solution, test1) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    EXPECT_EQ(sol.diameterOfBinaryTree(root), 3);
}

TEST(Solution, test2) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    EXPECT_EQ(sol.diameterOfBinaryTree(root), 1);
}

TEST(Solution, test3) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(sol.diameterOfBinaryTree(root), 0);
}

TEST(Solution, test4) {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->left->right = new TreeNode(9);
    root->right->right = new TreeNode(8);
    EXPECT_EQ(sol.diameterOfBinaryTree(root), 6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
