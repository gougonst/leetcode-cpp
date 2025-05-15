#include "all_paths_from_source_to_target.h"

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int target = graph.size() - 1;
    vector<vector<int>> allPaths;
    vector<int> path{0};
    _dfs(graph, allPaths, path, visited, 0, target);
    return allPaths;
}

void Solution::_dfs(vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& path, int cur, int target) {
    if (cur == target) {
        allPaths.push_back(path);
        return;
    }

    for (auto& neighbor: graph[cur]) {
        path.push_back(neighbor);
        _dfs(graph, allPaths, path, neighbor, target);
        path.pop_back();
    }
}
