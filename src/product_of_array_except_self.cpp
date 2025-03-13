#include "product_of_array_except_self.h"
#include <unordered_set>

// Time Complexity: 2n, O(n)
// Space Complexity (extra): O(n)
vector<int> Solution::productExceptSelf1(vector<int>& nums) {
    int totalProduct = 1;
    unordered_set<int> zeroIndex;

    // It might multiply by 0
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            zeroIndex.insert(i);
            continue;
        }
        totalProduct *= nums[i];
    }

    vector<int> ans;
    // It might diveded by 0
    for (int i = 0; i < nums.size(); i++) {
        if (zeroIndex.size() > 1) {
            ans.push_back(0);
        } else if (zeroIndex.size() == 1) {
            if (zeroIndex.count(i))
                ans.push_back(totalProduct);
            else
                ans.push_back(0);
        } else {
            ans.push_back(totalProduct / nums[i]);
        }
    }
    return ans;
}

// Time Complexity: 2n, O(n)
// Space Complexity (extra): O(1)
vector<int> Solution::productExceptSelf2(vector<int>& nums) {
    vector<int> ans;
    int totalProduct = 1;
    int zeroCounter = 0;

    for (int& num: nums) {
        if (num == 0) {
            zeroCounter++;
            continue;
        }
        totalProduct *= num;
    }

    for (int& num: nums) {
        if (zeroCounter > 1 || (zeroCounter == 1 && num != 0)) {
            ans.push_back(0);
        } else if (zeroCounter == 1) {
            ans.push_back(totalProduct);
        } else {
            ans.push_back(totalProduct / num);
        }
    }
    return ans;
}

// Time Complexity: 2n, O(n)
// Space Complexity (extra): O(1)
vector<int> Solution::productExceptSelf3(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);

    int left = 1;
    for (int i = 0; i < nums.size(); i++) {
        ans[i] *= left;
        left *= nums[i];
    }

    int right = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }

    return ans;
}
