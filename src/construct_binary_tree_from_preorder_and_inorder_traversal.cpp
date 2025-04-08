#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"
#include <unordered_map>

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++)
        inorderMap[inorder[i]] = i;

    int curIdx = 0;
    TreeNode* root = _buildTree(preorder, inorderMap, curIdx, 0, inorder.size() - 1);
    return root;
}

// curIdx: preorder index
// l, r: inorder index
TreeNode* Solution::_buildTree(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& curIdx, int l, int r) {
    if (l > r)
        return nullptr;

    TreeNode *node = new TreeNode(preorder[curIdx++]);
    int center = inorderMap[node->val];
    node->left = _buildTree(preorder, inorderMap, curIdx, l, center  - 1);
    node->right = _buildTree(preorder, inorderMap, curIdx, center + 1, r);
    return node;
}
