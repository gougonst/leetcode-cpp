#include <algorithm>
#include "maximum_depth_of_binary_tree.h"

int Solution::maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = 1 + maxDepth(root->left);
    int rightDepth = 1 + maxDepth(root->right);
    return std::max(leftDepth, rightDepth);
}
