#include "container_with_most_water.h"

int Solution::maxArea(vector<int>& height) {
    int maxArea = 0;
    int l = 0, r = height.size() - 1;
    while (r > l) {
        int curArea = (r - l) * min(height[l], height[r]);
        maxArea = max(curArea, maxArea);
        if (height[l] > height[r])
            r--;
        else
            l++;
    }
    return maxArea;
}
