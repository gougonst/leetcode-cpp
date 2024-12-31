#include "tree_node.h"

class Solution {
public:
    bool isBalanced(TreeNode* root);
private:
    int _getTreeHeight(TreeNode* root);
};
