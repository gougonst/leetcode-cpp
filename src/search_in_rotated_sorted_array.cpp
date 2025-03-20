#include "search_in_rotated_sorted_array.h"

int Solution::search(vector<int>& nums, int target) {
    // Truncate point is the first element.
    // Do binary search:
    //  # Target in right slice
    //  if target < truncate:
    //      # Current is right slice
    //      if pivot < truncate:
    //          if target < pivot:
    //              search left
    //          else:
    //              search right
    //      # Current is left slice
    //      else:
    //          search right
    //  # Target in left slice
    //  else:
    //      # Current is right slice
    //      if pivot < truncate:
    //          search left
    //      else:
    //          if target < pivot:
    //              search left
    //          else:
    //              search right
    int n = nums.size();
    int truncate = nums[0];
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        int pivot = nums[middle];
        if (pivot == target)
            return middle;
        if (target < truncate) {
            if (pivot < truncate) {
                if (target < pivot) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                left = middle + 1;
            }
        } else {
            if (pivot < truncate) {
                right = middle - 1;
            } else {
                if (target < pivot) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }
    }
    return -1;
}
