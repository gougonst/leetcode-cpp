#include "permutations.h"

vector<vector<int>> Solution::permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<bool> visited(nums.size(), false);
    vector<int> cur;
    _dfs(ans, nums, visited, cur, nums.size(), 0);
    return ans;
}

void Solution::_dfs(vector<vector<int>> &ans,
                    vector<int> &nums,
                    vector<bool> &visited,
                    vector<int> &cur,
                    int n,
                    int d) {
    if (d == n) {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        cur.push_back(nums[i]);
        _dfs(ans, nums, visited, cur, n, d + 1);
        visited[i] = false;
        cur.pop_back();
    }
}
