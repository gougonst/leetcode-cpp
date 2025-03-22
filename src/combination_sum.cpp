#include "combination_sum.h"
#include <unordered_map>
#include <algorithm>

// This method will have duplcate answer
vector<vector<int>> Solution::combinationSum1(vector<int>& candidates, int target) {
    unordered_map<int, vector<vector<int>>> combinations{{0, {{}}}};
    for (int i = 0; i <= target; i++) {
        // Fill the target i combinations
        for (auto &candidate: candidates) {
            int complement = i - candidate;
            if (!combinations.count(complement))
                continue;

            if (!combinations.count(i))
                combinations[i] = {};
            for (auto &compCandidate: combinations[complement]) {
                vector<int> newCombination{candidate};
                newCombination.insert(
                    newCombination.end(),
                    compCandidate.begin(),
                    compCandidate.end()
                );
                combinations[i].push_back(newCombination);
            }
        }
    }
    return combinations[target];
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> cur;
    // It needs to do sort so that it can prunning the tree
    sort(candidates.begin(), candidates.end());
    _dfs(ans, candidates, cur, candidates.size(), 0, target);
    return ans;
}

void Solution::_dfs(vector<vector<int>> &ans,
    vector<int> &candidates,
    vector<int> &cur,
    int n,
    int start,
    int target) {
    if (target == 0) {
        ans.push_back(cur);
        return;
    }
    for (int i = start; i < n; i++) {
        // Prunning here
        if (candidates[i] > target)
            break;
        cur.push_back(candidates[i]);
        _dfs(ans, candidates, cur, n, i, target - candidates[i]);
        cur.pop_back();
    }
}
