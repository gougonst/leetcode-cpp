#include <set>
#include "3sum.h"

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    sort(begin(nums), end(nums));
    unordered_map<int, int> countNum;
    for (auto &num: nums)
        countNum[num]++;
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size() - 1; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int target = 0 - nums[i] - nums[j];
            if (!countNum.count(target))
                continue;
            if (target < nums[j])
                continue;
            if (countNum[target] >= 1 + (nums[i] == target) + (nums[j] == target))
                ans.push_back({nums[i], nums[j], target});
        }
    }
    return ans;
}

vector<vector<int>> Solution::threeSum2(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = nums.size() - 1;
        int target = 0 - nums[i];
        while (j < k) {
            int candidate = nums[j] + nums[k];
            if (candidate == target) {
                ans.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
            else if (candidate < target)
                j++;
            else
                k--;
        }
    }
    return ans;
}
