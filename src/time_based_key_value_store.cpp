#include "time_based_key_value_store.h"

TimeMap::TimeMap() {

}

void TimeMap::set(string key, string value, int timestamp) {
    _map[key].push_back({timestamp, value});
}

string TimeMap::get(string key, int timestamp) {
    // Binary search, Find the lower bound of timestamp in _map[key]
    int n = _map[key].size();
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (_map[key][mid].first <= timestamp)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left == 0 ? "" : _map[key][--left].second;
}
