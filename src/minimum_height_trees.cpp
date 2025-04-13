#include "minimum_height_trees.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

vector<int> Solution::findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1)
        return {0};

    vector<vector<int>> tree(n);
    vector<int> degrees(n, 0);
    for (auto& edge: edges) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
        degrees[edge[0]]++;
        degrees[edge[1]]++;
    }

    queue<int> leaves;
    for (int i = 0; i < n; i++) {
        if (degrees[i] == 1)
            leaves.push(i);
    }

    int remainNode = n;
    while (remainNode > 2) {
        int layerSize = leaves.size();
        remainNode -= layerSize;
        for (int i = 0; i < layerSize; i++) {
            int leaf = leaves.front();
            leaves.pop();
            for (auto& parentNode: tree[leaf])
                if (--degrees[parentNode] == 1) {
                    leaves.push(parentNode);
            }
        }
    }

    vector<int> roots;
    while (!leaves.empty()) {
        roots.push_back(leaves.front());
        leaves.pop();
    }
    return roots;
}
