#include "maximum_subarray.h"

int Solution::maxSubArray(vector<int>& nums) {
    int curSum = 0;
    int maxSum = INT_MIN;
    for (const auto& num: nums) {
        if (curSum + num < num) {
            curSum = num;
        } else {
            curSum += num;
        }
        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}
