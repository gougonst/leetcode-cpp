#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);
private:
    void _dfs(vector<vector<int>> &ans,
              vector<int> &nums,
              vector<bool> &visited,
              vector<int> &cur,
              int n,
              int d);
};
