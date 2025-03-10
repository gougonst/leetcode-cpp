#include <math.h>
#include <queue>
#include "k_closest_points_to_origin.h"

vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, vector<int>>> maxHeap;
    for (auto &point: points) {
        maxHeap.push({point[0] * point[0] + point[1] * point[1], point});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    vector<vector<int>> ans;
    while (!maxHeap.empty()) {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ans;
}

int Solution::_euclidien_distance(vector<int> &point) {
    return pow(point[0], 2) + pow(point[1], 2);
}
