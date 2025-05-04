#include "find_the_duplicate_number.h"

// Binary Search, there should be exact n numbers smaller or equal to n
// TC: O(nlogn), SC: O(1)
int Solution::findDuplicate1(vector<int>& nums) {
    int duplicate = 0;
    int left = 1, right = nums.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        int count = _smaller_or_equal(nums, middle);
        if (count <= middle) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
            duplicate = middle;
        }
    }
    return duplicate;
}

int Solution::_smaller_or_equal(vector<int>& nums, int cur) {
    int count = 0;
    for (auto& num: nums) {
        if (num <= cur)
            count++;
    }
    return count;
}

// Floyd Algorithm
// TC: O(n), SC: O(1)
int Solution::findDuplicate2(vector<int>& nums) {
    // tortoise: slow, move 1
    // hare: fast, move 2
    // target: find the entrance of cycle

    // step1: find the meet point of tortoise and hare
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // step2: find the entrace of cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return tortoise;
}
