#include "all_paths_from_source_lead_to_destination.h"
#include <unordered_map>
#include <unordered_set>

bool Solution::leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> graph;
    vector<State> visited(n, notVisited);
    for (auto& edge: edges)
        graph[edge[0]].push_back(edge[1]);

    return _dfs(graph, visited, source, destination);
}

bool Solution::_dfs(unordered_map<int, vector<int>>& graph, vector<State>& visited, int cur, int destination) {
    if (graph[cur].empty())
        return cur == destination;

    if (visited[cur] != notVisited)
        return visited[cur] == isTrue;

    visited[cur] = isVisited;
    for (auto& neighbor: graph[cur]) {
        if (!_dfs(graph, visited, neighbor, destination))
            return false;
    }
    visited[cur] = valid;
    return true;
}
