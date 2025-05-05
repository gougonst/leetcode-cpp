#include "longest_increasing_subsequence.h"

// [10, 9, 2, 5, 3, 7, 101, 18]
int Solution::lengthOfLIS1(vector<int>& nums) {
    int n = nums.size();
    vector<int> longestLengths(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                longestLengths[i] = max(longestLengths[i], longestLengths[j] + 1);
            }
        }
    }

    return *max_element(longestLengths.begin(), longestLengths.end());
}

int Solution::lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> smallestEndWithSubsequence;
    smallestEndWithSubsequence.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        int cur = nums[i];
        if (cur > smallestEndWithSubsequence.back()) {
            smallestEndWithSubsequence.push_back(cur);
        }
        else {
            int j = 0;
            while (cur > nums[j]) {
                j++;
            }
            smallestEndWithSubsequence[j] = cur;
        }
    }
    return smallestEndWithSubsequence.size();
}

int Solution::lengthOfLIS3(vector<int>& nums) {
    int n = nums.size();
    vector<int> smallestEndWithSubsequence;
    smallestEndWithSubsequence.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        int cur = nums[i];
        if (cur > smallestEndWithSubsequence.back()) {
            smallestEndWithSubsequence.push_back(cur);
        }
        else {
            int j = _binarySearch(smallestEndWithSubsequence, cur);
            smallestEndWithSubsequence[j] = cur;
        }
    }
    return smallestEndWithSubsequence.size();
}

// 1, 3, 5, 6, 8, 9. Find 4
int Solution::_binarySearch(vector<int>& smallestEndWithSubquence, int num) {
    int l = 0, r = smallestEndWithSubquence.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (smallestEndWithSubquence[m] < num) {
            l = m + 1;
        }
        else if (smallestEndWithSubquence[m] > num) {
            r = m;
        }
        else {
            return m;
        }
    }
    return l;
}
