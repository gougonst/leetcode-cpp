#include "find_if_path_exists_in_graph.h"
#include <queue>
#include <unordered_set>

bool Solution::validPath1(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<bool> visited(n, false);
    visited[source] = true;

    vector<unordered_set<int>> graph(n, unordered_set<int>());
    for (auto& edge: edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int layerSize = q.size();
        for (int i = 0; i < layerSize; i++) {
            int node = q.front();
            if (node == destination)
                return true;
            q.pop();
            visited[node] = true;
            for (auto& neighbor: graph[node]) {
                if (visited[neighbor])
                    continue;
                q.push(neighbor);
            }
        }
    }
    return false;
}

UnionFind::UnionFind(int n) {
    _rank = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
        _root.push_back(i);
}

int UnionFind::find(int x) {
    if (_root[x] == x)
        return x;
    return _root[x] = find(_root[x]);
}

void UnionFind::unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (_rank[rootX] == _rank[rootY]) {
            _root[rootX] = _root[rootY];
            _rank[rootY]++;
        }
        else if (_rank[rootX] < _rank[rootY]) {
            _root[rootX] = _root[rootY];
        }
        else {
            _root[rootY] = _root[rootX];
        }
    }
}

bool Solution::validPath2(int n, vector<vector<int>>& edges, int source, int destination) {
    UnionFind unionFind = UnionFind(n);
    for (auto& edge: edges) {
        unionFind.unionSet(edge[0], edge[1]);
    }
    return unionFind.find(source) == unionFind.find(destination);
}

