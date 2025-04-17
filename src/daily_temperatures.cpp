#include "daily_temperatures.h"
#include <stack>

// [70, 71, 72, 71, 70, 69, 73, 74]
// (70) [0]
// 71: () [1, 0] (71)
// 72: () [1, 1, 0] (72)
// 71: (72, 71) [1, 1, 0, 0]
// 70: (72, 71, 70) [1, 1, 0, 0, 0]
// 69: (72, 71, 70, 69) [1, 1, 0, 0, 0, 0]
// 73: (72, 71, 70) i = 1 [1, 1, 0, 0, 0, 1]
// (72, 71) i = 2 [1, 1, 0, 0, 2, 1]
// (72) i = 3 [1, 1, 0, 3, 2, 1]
// () i = 4 [1, 1, 4, 3, 2, 1] [1, 1, 4, 3, 2, 1, 0](73)
// 74: () [1, 1, 4, 3, 2, 1, 1, 0]
vector<int> Solution::dailyTemperatures1(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> intervals(n, 0);
    stack<int> lowers;
    for (int i = 0; i < n; i++) {
        while (!lowers.empty() && temperatures[i] > temperatures[lowers.top()]) {
            int lowerIndex = lowers.top();
            lowers.pop();
            intervals[lowerIndex] = i - lowerIndex;
        }
        lowers.push(i);
    }
    return intervals;
}

vector<int> Solution::dailyTemperatures2(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    int hottest = 0;
    for (int curDay = n - 1; curDay >= 0; curDay--) {
        if (temperatures[curDay] >= hottest) {
            hottest = temperatures[curDay];
            continue;
        }
        int day = 1;
        while (temperatures[curDay] > temperatures[curDay + day]) {
            day += ans[curDay + day];
        }
        ans[curDay] = day;
    }
    return ans;
}
