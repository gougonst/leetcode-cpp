#include "maximum_product_subarray.h"

int Solution::maxProduct1(vector<int>& nums) {
    int maxProduct = INT_MIN;
    int start = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            vector<int> segment = vector<int>(nums.begin() + start, nums.begin() + i);
            maxProduct = max(maxProduct, _maxNonZeroProduct(segment));
            maxProduct = max(maxProduct, 0);
            start = i + 1;
        }
    }
    if (start < nums.size()) {
        vector<int> segment = vector<int>(nums.begin() + start, nums.end());
        return max(maxProduct, _maxNonZeroProduct(segment));
    }
    return maxProduct;
}

int Solution::_maxNonZeroProduct(vector<int>& nums) {
    if (nums.size() == 0)
        return INT_MIN;
    if (nums.size() == 1)
        return nums[0];

    int totalProduct = 1;
    for (auto& num: nums)
        totalProduct *= num;

    if (totalProduct > 0)
        return totalProduct;

    int left = 0, right = nums.size() - 1;
    int leftProduct = nums[left], rightProduct = nums[right];
    while (nums[left] > 0 || nums[right] > 0) {
        if (nums[left] > 0)
            leftProduct *= nums[++left];
        if (nums[right] > 0)
            rightProduct *= nums[--right];
    }
    return totalProduct / max(leftProduct, rightProduct);
}

// DP, Kadane's Algorithm
// Fix i-th element
// f1(n) = largest product if we fix the i-th element
// f2(n) = smallest product if we fix the i-th element
// Find the max(f(0...n))
//  f1(n) =
//      if A[n] >= 0:
//          A[n] * f1(n)
//      if A[n] < 0:
//          A[n] * f2(n)
//  f2(n) =
//      if A[n] >= 0:
//          A[n] * f2(n)
//      if A[n] < 0:
//          A[n] * f1(n)
int Solution::maxProduct2(vector<int>& nums) {
    int curMax = nums[0];
    int curMin = nums[0];
    int result = curMax;
    for (int i = 1; i < nums.size(); i++) {
        int tempMax = max(nums[i] * curMax, max(nums[i] * curMin, nums[i]));
        curMin = min(nums[i] * curMin, min(nums[i] * curMax, nums[i]));
        curMax = tempMax;
        result = max(result, curMax);
    }
    return result;
}
