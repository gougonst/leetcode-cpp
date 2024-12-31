#include <gtest/gtest.h>
#include "lowest_common_ancestor_of_a_binary_search_tree.h"

TEST(Solution, test1) {
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);

    EXPECT_EQ(sol.lowestCommonAncestor(root, p, q), root);
}

TEST(Solution, test2) {
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(4);

    EXPECT_EQ(sol.lowestCommonAncestor(root, p, q), root->left);
}

TEST(Solution, test3) {
    Solution sol;

    TreeNode* root = nullptr;

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(4);

    EXPECT_EQ(sol.lowestCommonAncestor(root, p, q), nullptr);
}

TEST(Solution, test4) {
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(0);
    TreeNode* q = new TreeNode(3);

    EXPECT_EQ(sol.lowestCommonAncestor(root, p, q), root->left);
}

TEST(Solution, test5) {
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(3);
    TreeNode* q = new TreeNode(5);

    EXPECT_EQ(sol.lowestCommonAncestor(root, p, q), root->left->right);
}

TEST(Solution, test6) {
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(4);
    TreeNode* q = new TreeNode(2);

    EXPECT_EQ(sol.lowestCommonAncestor(root, p, q), root->left);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
