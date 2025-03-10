#include "tree_node.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root);
private:
    int _getMaxDistanceOfSubtree(TreeNode* node, int &maxDistance);
};
