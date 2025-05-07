#include "graph_valid_tree.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

bool Solution::validTree1(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1)
        return false;

    unordered_map<int, unordered_set<int>> graph;
    for (auto& edge: edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    unordered_set<int> visited;
    queue<int> q;
    q.push(0);
    visited.insert(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto& neighbor: graph[node]) {
            if (visited.find(neighbor) != visited.end())
                continue;
            q.push(neighbor);
            visited.insert(neighbor);
        }
    }
    return visited.size() == n;
}

bool Solution::validTree2(int n, vector<vector<int>>& edges) {
    UnionFind unionFind = UnionFind(n);
    for (auto& edge: edges) {
        int node1 = edge[0];
        int node2 = edge[1];
        if (unionFind.find(node1) == unionFind.find(node2)) {
            return false;
        }
        else {
            unionFind.unionSet(node1, node2);
        }
    }
    return unionFind.getTreeNumber() == 1;
}
