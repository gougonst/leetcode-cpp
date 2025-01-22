#include "majority_element.h"

int Solution::majorityElement(vector<int>& nums) {
    int res = 0;
    int frequency = 0;

    for (auto& num: nums) {
        if (frequency == 0) {
            res = num;
        }
        frequency += (res == num) ? 1 : -1;
    }

    return res;
}
