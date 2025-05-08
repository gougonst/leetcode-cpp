#include "number_of_connected_components_in_an_undirected_graph.h"

int Solution::countComponents(int n, vector<vector<int>>& edges) {
    UnionFind unionFind = UnionFind(n);
    for (auto& edge: edges) {
        unionFind.unionSet(edge[0], edge[1]);
    }
    return unionFind.getNumberOfGraph();
}
