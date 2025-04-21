#include "house_robber.h"
#include <algorithm>

// 1, 2, 3, 1
// f(0) = 2 (0)
// f(1) = 7 (1)
// f(2) = 11 (0, 2)
// f(3) = 11 (0, 2)
// f(4) = 12 (0, 2, 4)

// 10, 2, 3, 11
// f(0) = 10 (0)
// f(1) = 10 (0)
// f(2) = 13 (0, 2)
// f(3) = 21 (0, 3)
// Assume the transition function is the maximum sum if we rob to A[n]
// f(n) = max(f(n-2) + A[n], f(n-1))
// Bottom-up
int Solution::rob1(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    // Assign the maximum value of rob to n-th house
    vector<int> maxRobs(n, 0);
    maxRobs[0] = nums[0];
    maxRobs[1] = max(nums[0], nums[1]);

    // Calculate the maximum rob f(n) = max(f(n-2) + A[n], f(n-1))
    for (int i = 2; i < n; i++) {
        int candidate1 = maxRobs[i - 2] + nums[i];
        int candidate2 = maxRobs[i - 1];
        maxRobs[i] = max(candidate1, candidate2);
    }

    return maxRobs[n - 1];
}

// Bottom-up enhance memory usage
int Solution::rob2(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    nums[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        int candidate1 = nums[i - 2] + nums[i];
        int candidate2 = nums[i - 1];
        nums[i] = max(candidate1, candidate2);
    }

    return nums[n - 1];
}

// Top-down
int Solution::rob3(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, -1);
    return _robForm(nums, memo, n - 1);
}

int Solution::_robForm(vector<int>& nums, vector<int>& memo, int i) {
    if (i < 0)
        return 0;

    if (memo[i] > -1)
        return memo[i];

    memo[i] = max(_robForm(nums, memo, i - 1), _robForm(nums, memo, i - 2) + nums[i]);
    return memo[i];
}
