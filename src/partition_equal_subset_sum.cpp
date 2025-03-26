#include "partition_equal_subset_sum.h"
#include <unordered_set>
#include <unordered_map>
#include <queue>

bool Solution::canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (auto &num: nums)
        totalSum += num;
    if (totalSum % 2 != 0)
        return false;

    /*
    If any sum = sum(nums) / 2 -> it can be partition
    f(sum) = f(sum - x) + x
    dp[i][j] = true if dp[i - 1][j - num_i]
    */
    vector<bool> dp(totalSum + 1, false);
    dp[0] = true;
    for (auto &num: nums) {
        for (int i = totalSum; i >= 0; i--) {
            if (dp[i])
                dp[i + num] = true;
        }
        if (dp[totalSum / 2])
            return true;
    }
    return false;
}
