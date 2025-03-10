#include <algorithm>
#include "insert_interval.h"

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    auto it = intervals.begin();
    while (it != intervals.end() && newInterval[0] > (*it)[0]) {
        it++;
    }
    intervals.insert(it, newInterval);

    vector<vector<int>> newIntervals;
    for (auto& interval: intervals) {
        if (newIntervals.empty() || interval[0] > newIntervals.back()[1]) {
            newIntervals.push_back(interval);
        } else {
            newIntervals.back()[1] = max(newIntervals.back()[1], interval[1]);
        }
    }
    return newIntervals;
}
