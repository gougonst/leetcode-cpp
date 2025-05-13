#include "all_paths_from_source_to_target.h"
#include <unordered_set>

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int target = graph.size() - 1;
    vector<vector<int>> allPaths;
    vector<int> path{0};
    unordered_set<int> visited;
    _dfs(graph, allPaths, path, visited, 0, target);
    return allPaths;
}

void Solution::_dfs(vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& path, unordered_set<int>& visited, int cur, int target) {
    if (cur == target) {
        allPaths.push_back(path);
        return;
    }

    for (auto& neighbor: graph[cur]) {
        path.push_back(neighbor);
        _dfs(graph, allPaths, path, visited, neighbor, target);
        path.pop_back();
    }
}
