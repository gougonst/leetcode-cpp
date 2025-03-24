#include "sort_colors.h"

void Solution::sortColors1(vector<int>& nums) {
    int curNumber = 0;
    int lastProcessed = 0;
    while (lastProcessed < nums.size()) {
        int curProcessed = lastProcessed;
        while (lastProcessed < nums.size() && curProcessed < nums.size()) {
            if (nums[lastProcessed] == curNumber) {
                lastProcessed++;
            }
            else {
                while (curProcessed++ < lastProcessed);
                if (curProcessed < nums.size() && nums[curProcessed] == curNumber) {
                    int temp = nums[lastProcessed];
                    nums[lastProcessed] = nums[curProcessed];
                    nums[curProcessed] = temp;
                    lastProcessed++;
                }
            }
        }
        curNumber++;
    }
}

// Dutch National Flag Problem
void Solution::sortColors2(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (mid < right) {
        if (nums[mid] == 0) {
            swap(nums[left++], nums[mid++]);
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[right--], nums[mid]);
        }
    }
}
