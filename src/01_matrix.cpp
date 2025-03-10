#include <queue>
#include "01_matrix.h"

vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int, int>> candidates;
    vector<pair<int, int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0)
                candidates.push({i, j});
            else
                mat[i][j] = INT_MAX;
        }
    }

    while (!candidates.empty()) {
        pair<int, int> candidate = candidates.front();
        candidates.pop();
        int row = candidate.first;
        int col = candidate.second;
        for (auto& direction: directions) {
            int newRow = row + direction.first;
            int newCol = col + direction.second;
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n ||
                mat[row][col] + 1 > mat[newRow][newCol])
                continue;
            mat[newRow][newCol] = mat[row][col] + 1;
            candidates.push({newRow, newCol});
        }
    }
    return mat;
}
