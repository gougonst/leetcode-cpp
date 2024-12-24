#include "invert_binary_tree.h"

TreeNode* Solution::invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* tempNode = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tempNode);
    return root;
}
