#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget1(vector<vector<int>>& graph);
    vector<vector<int>> allPathsSourceTarget2(vector<vector<int>>& graph);
private:
    void _dfs(vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& path, int cur, int target);
};
