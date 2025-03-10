#include <queue>
#include "binary_tree_level_order_traversal.h"

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    if (root == nullptr)
        return {};

    vector<vector<int>> ans;
    queue<TreeNode*> level;

    level.push(root);
    while (!level.empty()) {
        vector<int> levelAns;
        int levelSize = level.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = level.front();
            levelAns.push_back(node->val);
            if (node->left)
                level.push(node->left);
            if (node->right)
                level.push(node->right);
            level.pop();
        }
        ans.push_back(levelAns);
    }
    return ans;
}
