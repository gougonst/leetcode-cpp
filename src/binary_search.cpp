#include "binary_search.h"

int Solution::search(vector<int>& nums, int target) {
    return _search(nums, target, 0, nums.size() - 1);
}

int Solution::_search(vector<int>& nums, int target, int left, int right) {
    if (left > right) {
        return -1;
    }

    int middle = (left + right) / 2;
    if (nums[middle] == target) {
        return middle;
    }
    if (target < nums[middle]) {
        return _search(nums, target, left, middle - 1);
    } else {
        return _search(nums, target, middle + 1, right);
    }
}
