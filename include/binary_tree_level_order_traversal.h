#include "tree_node.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root);
private:
    vector<vector<int>> bfs(vector<vector<int>> &ans,
                            vector<TreeNode*> &level);
};
