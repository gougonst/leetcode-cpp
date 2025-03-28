#include "tree_node.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rightSideView1(TreeNode* root);
    vector<int> rightSideView2(TreeNode* root);
private:
    void _dfs(vector<int> &rightSides, TreeNode* node, int level)
};
