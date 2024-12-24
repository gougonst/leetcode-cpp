#include <gtest/gtest.h>
#include "tree_node.h"

TEST(Solution, test1) {
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(1);

    EXPECT_TRUE(isTreeEqual(root1, root2));
}

TEST(Solution, test2) {
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);

    EXPECT_FALSE(isTreeEqual(root1, root2));
}

TEST(Solution, test3) {
    TreeNode *root1 = new TreeNode(1);
    EXPECT_FALSE(isTreeEqual(root1, nullptr));
}

TEST(Solution, test4) {
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(2);
    TreeNode *root2 = new TreeNode(2);
    EXPECT_FALSE(isTreeEqual(root1, root2));
}

TEST(Solution, test5) {
    TreeNode *root1 = new TreeNode(2);
    root1->right = new TreeNode(2);
    TreeNode *root2 = new TreeNode(2);
    EXPECT_FALSE(isTreeEqual(root1, root2));
}

TEST(Solution, test6) {
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);

    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right = new TreeNode(7);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(9);

    EXPECT_TRUE(isTreeEqual(root1, root2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
