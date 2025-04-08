#include <vector>
#include "tree_node.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
private:
    void _buildTree(TreeNode* node, vector<int>& preorder, unordered_map<int, int>& inorderMap, int curIdx);
};
