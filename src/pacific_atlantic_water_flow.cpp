#include "pacific_atlantic_water_flow.h"

vector<vector<int>> Solution::pacificAtlantic(vector<vector<int>>& heights) {
    // Use a 2d-array to note that whether grid cell can flow to ocean or not.
    _rows = heights.size();
    _cols = heights[0].size();
    _heights = heights;
    _flowMap = vector<vector<vector<bool>>>(_rows,
        vector<vector<bool>>(_cols,
            vector<bool>(2, false)));

    for (int i = 0; i < _rows; i++) {
        _islandFlowToOcean(i, 0, PACIFIC_OCEAN, INT_MIN);
        _islandFlowToOcean(i, _cols - 1, ATLANTIC_OCEAN, INT_MIN);
    }
    for (int i = 0; i < _cols; i++) {
        _islandFlowToOcean(0, i, PACIFIC_OCEAN, INT_MIN);
        _islandFlowToOcean(_rows - 1, i, ATLANTIC_OCEAN, INT_MIN);
    }

    vector<vector<int>> ans;
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            if (_flowMap[r][c][PACIFIC_OCEAN] &&
                _flowMap[r][c][ATLANTIC_OCEAN]) {
                ans.push_back({r, c});
            }
        }
    }
    return ans;
}

void Solution::_islandFlowToOcean(int r, int c, int ocean) {
    _flowMap[r][c][ocean] = true;
    vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (auto& dir: dirs) {
        int nextr = r + dir.first;
        int nextc = c + dir.second;

        if (r < 0 || r >= _rows || c < 0 || c >= _cols || _heights[r][c] > _heights[r][c])
            return;
        if (_flowMap[nextr][nextc][ocean])
            continue;
        _islandFlowToOcean(nextr, nextc, ocean, _heights[nextr][nextc]);
    }
}
