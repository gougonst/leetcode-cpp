#include "binary_tree_right_side_view.h"
#include <queue>

// BFS
vector<int> Solution::rightSideView1(TreeNode* root) {
    if (!root)
        return {};

    queue<TreeNode*> layer;
    layer.push(root);

    vector<int> rightSides;
    while (!layer.empty()) {
        int n = layer.size();
        TreeNode* node = nullptr;
        for (int i = 0; i < n; i++) {
            node = layer.front();
            layer.pop();
            if (node->left)
                layer.push(node->left);
            if (node->right)
                layer.push(node->right);
        }
        rightSides.push_back(node->val);
    }
    return rightSides;
}

// DFS
vector<int> Solution::rightSideView1(TreeNode* root) {
    vector<int> rightSides;
    _dfs(rightSides, root, 0);
    return rightSides;
}

void Solution::_dfs(vector<int> &rightSides, TreeNode* node, int level) {
    if (!node)
        return;

    if (rightSides.size() == level)
        rightSides.push_back(node->val);
    _dfs(rightSides, node->right);
    _dfs(rightSides, node->left);
}
