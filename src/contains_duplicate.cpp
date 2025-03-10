#include <unordered_set>
#include "contains_duplicate.h"

bool Solution::containsDuplicate1(vector<int>& nums) {
    unordered_set<int> set;
    for (const auto& num: nums) {
        if (set.count(num)) {
            return true;
        }
        set.insert(num);
    }
    return false;
}

bool Solution::containsDuplicate2(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    return nums.size() > set.size();
}
