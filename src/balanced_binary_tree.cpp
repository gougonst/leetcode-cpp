#include <algorithm>
#include "balanced_binary_tree.h"

bool Solution::isBalanced(TreeNode* root) {
    return _getTreeHeight(root) != -1;
}

int Solution::_getTreeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = _getTreeHeight(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = _getTreeHeight(root->right);
    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return std::max(leftHeight, rightHeight) + 1;
}
