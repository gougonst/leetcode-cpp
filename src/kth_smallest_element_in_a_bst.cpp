#include "kth_smallest_element_in_a_bst.h"

int Solution::kthSmallest(TreeNode* root, int k) {
    return _inOrder(root, k);
}

int Solution::_inOrder(TreeNode* root, int& k) {
    if (root == nullptr)
        return -1;

    int ret = this->_inOrder(root->left, k);
    if (ret >= 0)
        return ret;
    if (--k == 0)
        return root->val;
    return this->_inOrder(root->right, k);
}
