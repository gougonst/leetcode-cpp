#include <gtest/gtest.h>
#include "invert_binary_tree.h"
#include "tree_node.h"

TEST(Solution, test1) {
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode *expectedRoot = new TreeNode(4);
    expectedRoot->left = new TreeNode(7);
    expectedRoot->left->left = new TreeNode(9);
    expectedRoot->left->right = new TreeNode(6);
    expectedRoot->right = new TreeNode(2);
    expectedRoot->right->left = new TreeNode(3);
    expectedRoot->right->right = new TreeNode(1);

    EXPECT_TRUE(isTreeEqual(sol.invertTree(root), expectedRoot));
}

TEST(Solution, test2) {
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode *expectedRoot = new TreeNode(2);
    expectedRoot->left = new TreeNode(3);
    expectedRoot->right = new TreeNode(1);

    EXPECT_TRUE(isTreeEqual(sol.invertTree(root), expectedRoot));
}

TEST(Solution, test3) {
    Solution sol;
    EXPECT_TRUE(isTreeEqual(sol.invertTree(nullptr), nullptr));
}

TEST(Solution, test4) {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    TreeNode *expectedRoot = new TreeNode(1);
    EXPECT_TRUE(isTreeEqual(sol.invertTree(root), expectedRoot));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
