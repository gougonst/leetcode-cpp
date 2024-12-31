#include "lowest_common_ancestor_of_a_binary_search_tree.h"

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr ||
        root->val >= p->val && root->val <= q->val ||
        root->val <= p->val && root->val >= q->val) {
        return root;
    }

    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return nullptr;
    }
}
