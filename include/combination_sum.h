#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
private:
    void _dfs(vector<vector<int>> &ans,
              vector<int> &candidates,
              vector<int> &cur,
              int n,
              int start,
              int target);
};
