#include "next_permutation.h"

// [1, 2, 3, 4] + + +
// [1, 2, 4, 3] + + -
// [1, 3, 2, 4] + - +
// [1, 3, 4, 2] + + -
// [1, 4, 2, 3] + - +
// [1, 4, 3, 2] + - -
// [2, 1, 3, 4] - + +
// [2, 1, 5, 3, 4, 6, 7]
// [2, 1, 1, 5, 4, 3]
// [1, 1, 3, 4]
// [1, 1, 4, 3]
// [1, 3, 1, 4]
// [1, 3, 4, 1]
// [1, 4, 1, 3]
// [1, 4, 3, 1]
// [3, 1, 1, 4]
void Solution::nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // Find the decreasing element from low bit to high bit
    int decreasing = n - 2;
    while (decreasing >= 0 && nums[decreasing] >= nums[decreasing + 1]) {
        decreasing--;
    }

    if (decreasing >= 0) {
        // Find the smallest element bigger than decreasing element
        int swapping = n - 1;
        while (nums[swapping] <= nums[decreasing]) {
            swapping--;
        }

        // Swap the smallest element and decreasing element
        swap(nums[decreasing], nums[swapping]);
    }

    // Reverse the elements that behind the decreasing element
    reverse(nums.begin() + decreasing + 1, nums.end());
}
