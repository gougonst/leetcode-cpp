#include <algorithm>
#include "diameter_of_binary_tree.h"

int Solution::diameterOfBinaryTree(TreeNode* root) {
    // Calculate the distance in depth between the nodes of two subtrees
    // Use post-order traversal
    int maxDistance = 0;
    int depth = _getMaxDistanceOfSubtree(root, maxDistance);
    return maxDistance;
}

int Solution::_getMaxDistanceOfSubtree(TreeNode* node, int &maxDistance) {
    if (node == nullptr) {
        return 0;
    }

    int leftDepth = _getMaxDistanceOfSubtree(node->left, maxDistance);
    int rightDepth = _getMaxDistanceOfSubtree(node->right, maxDistance);

    int distance = leftDepth + rightDepth;
    maxDistance = (distance > maxDistance) ? distance : maxDistance;

    return std::max(leftDepth, rightDepth) + 1;
}
