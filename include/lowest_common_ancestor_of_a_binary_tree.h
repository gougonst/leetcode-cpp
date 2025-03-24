#include "tree_node.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q);
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);
private:
    bool _findAncestors(vector<TreeNode*> &ancestors, TreeNode* root, TreeNode* target);
};
