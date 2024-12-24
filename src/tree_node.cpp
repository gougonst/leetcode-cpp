#include "tree_node.h"

bool isTreeEqual(TreeNode* lhs, TreeNode* rhs) {
    if ((lhs == nullptr && rhs == nullptr) ||
        (lhs != nullptr && rhs != nullptr &&
         (lhs->val == rhs->val) &&
         (isTreeEqual(lhs->left, rhs->left) && isTreeEqual(lhs->right, rhs->right)))) {
        return true;
    }
    return false;
}
