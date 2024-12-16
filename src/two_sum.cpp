#include <unordered_map>
#include "two_sum.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numLocation;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int complement = target - num;
        if (numLocation.count(complement)) {
            return {numLocation[complement], i};
        } else {
            numLocation[num] = i;
        }
    }
    return {};
}
