#include "the_earliest_moment_when_everyone_become_boyfriend.h"

int Solution::earliestAcq(vector<vector<int>>& logs, int n) {
    UnionFind unionFind = UnionFind(n);
    auto cmp = [] (const auto& lhs, const auto& rhs) -> bool {
        return lhs[0] < rhs[0];
    };
    sort(logs.begin(), logs.end(), cmp);
    for (auto& log: logs) {
        unionFind.unionSet(log[1], log[2]);
        if (unionFind.getNumberOfGraph() == 1) {
            return log[0];
        }
    }
    return -1;
}
