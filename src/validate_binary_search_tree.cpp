#include "validate_binary_search_tree.h"
#include <stack>
using namespace std;

bool Solution::isValidBST1(TreeNode* root) {
    if (!root)
        return true;

    if (!isValidBST(root->left))
        return false;

    if (_prev && _prev->val >= root->val)
        return false;

    _prev = root;

    return isValidBST(root->right);
}

bool Solution::isValidBST2(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;
    while (cur || !s.empty()) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            if (prev && prev->val >= cur->val)
                return false;
            prev = cur;
            cur = cur->right;
        }
    }
    return true;
}
