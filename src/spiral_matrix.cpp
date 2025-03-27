#include "spiral_matrix.h"
#include <queue>

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int visitCount = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> directions;
    directions.push({1, 0});
    directions.push({0, -1});
    directions.push({-1, 0});
    directions.push({0, 1});

    vector<int> ans;
    pair<int, int> curDirection = {0, 1};
    pair<int, int> curPos = {0, 0};
    while (visitCount < m * n) {
        ans.push_back(matrix[curPos.first][curPos.second]);
        visited[curPos.first][curPos.second] = 1;
        visitCount++;

        int nextRow = curPos.first + curDirection.first;
        int nextCol = curPos.second + curDirection.second;
        if (nextRow >= m || nextRow < 0 || nextCol >= n || nextCol < 0 ||
            visited[nextRow][nextCol]) {
            curDirection = directions.front();
            directions.pop();
            directions.push(curDirection);
            nextRow = curPos.first + curDirection.first;
            nextCol = curPos.second + curDirection.second;
        }
        curPos = {nextRow, nextCol};
    }
    return ans;
}
