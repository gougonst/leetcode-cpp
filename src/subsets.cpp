#include "subsets.h"
#include <queue>
#include <algorithm>

vector<vector<int>> Solution::subsets1(vector<int>& nums) {
    int n = nums.size();
    queue<vector<int>> candidates;
    for (int i = 0; i < n; i++) {
        candidates.push({i});
    }

    vector<vector<int>> ans{{}};
    while (!candidates.empty()) {
        vector<int> candidate = candidates.front();
        candidates.pop();
        vector<int> subset;
        for (auto &idx: candidate) {
            subset.push_back(nums[idx]);
        }
        ans.push_back(subset);

        for (int i = candidate.back() + 1; i < n; i++) {
            vector<int> newCandidate = candidate;
            newCandidate.push_back(i);
            candidates.push(newCandidate);
        }
    }
    return ans;
}

vector<vector<int>> Solution::subsets2(vector<int>& nums) {
    /*
    f(-1) = {_}
    f(0) = {_, 0}
    f(1) = {_, 0, 1, 01}
    f(2) = {_, 0, 1, 01, 2, 02, 12, 012}
    */
    vector<vector<int>> ans{{}};
    for (auto &num: nums) {
        vector<vector<int>> newSubsets;
        for (auto &subset: ans) {
            vector<int> newSubset = subset;
            newSubset.push_back(num);
            newSubsets.push_back(newSubset);
        }
        for (auto &newSubset: newSubsets) {
            ans.push_back(newSubset);
        }
    }
    return ans;
}
