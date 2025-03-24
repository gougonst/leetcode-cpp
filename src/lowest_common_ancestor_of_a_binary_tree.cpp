#include "lowest_common_ancestor_of_a_binary_tree.h"
#include <vector>
using namespace std;

TreeNode* Solution::lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pAncestors, qAncestors;
    _findAncestors(pAncestors, root, p);
    _findAncestors(qAncestors, root, q);
    reverse(pAncestors.begin(), pAncestors.end());
    reverse(qAncestors.begin(), qAncestors.end());
    TreeNode* ancestor;
    while (!pAncestors.empty() && !qAncestors.empty() && pAncestors.back() == qAncestors.back()) {
        ancestor = pAncestors.back();
        pAncestors.pop_back();
        qAncestors.pop_back();
    }
    return ancestor;
}

bool Solution::_findAncestors(vector<TreeNode*> &ancestors, TreeNode* root, TreeNode* target) {
    if (!root)
        return false;
    ancestors.push_back(root);
    if (root == target ||
        _findAncestors(ancestors, root->left, target) ||
        _findAncestors(ancestors, root->right, target))
        return true;
    ancestors.pop_back();
    return false;
}

TreeNode* Solution::lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor2(root->left, p, q);
    TreeNode *right = lowestCommonAncestor2(root->right, p, q);
    if (left && right)
        return root;
    return left ? left : right;
}
