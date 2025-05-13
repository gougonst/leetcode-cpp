#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
private:
    void _dfs(vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& path, unordered_set<int>& visited, int cur, int target);
};
