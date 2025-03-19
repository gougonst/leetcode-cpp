#include "number_of_islands.h"
#include <queue>

// Push all lands into a queue.
// While queue is not empty, pop a land from queue, mark it as 0 and push the
//   land neighbors into the queue.
// If pop element is 0, means it has been visited, skip it.
int Solution::numIslands1(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> lands;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1')
                lands.push({r, c});
        }
    }

    int count = 0;
    queue<pair<int, int>> curLand;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!lands.empty()) {
        if (curLand.empty()) {
            pair<int, int> land{-1, -1};
            while (!lands.empty()) {
                pair<int, int> tmpLand = lands.front();
                lands.pop();
                if (grid[tmpLand.first][tmpLand.second] != '0') {
                    land = tmpLand;
                    break;
                }
            }
            if (land.first == -1 && land.second == -1)
                break;
            grid[land.first][land.second] = '0';
            curLand.push(land);
            count++;
        }

        pair<int, int> land = curLand.front();
        curLand.pop();
        for (auto& direction: directions) {
            pair<int, int> newLand{
                land.first + direction.first,
                land.second + direction.second
            };
            if (newLand.first < 0 || newLand.first >= rows ||
                newLand.second < 0 || newLand.second >= cols)
                continue;
            if (grid[newLand.first][newLand.second] == '1') {
                grid[newLand.first][newLand.second] = '0';
                curLand.push(newLand);
            }
        }
    }
    return count;
}

int Solution::numIslands2(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            count += grid[r][c] == '1';
            _dfs(grid, rows, cols, r, c);
        }
    }
    return count;
}

void Solution::_dfs(vector<vector<char>>& grid, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto& direction: directions)
        _dfs(grid, rows, cols, r + direction.first, c + direction.second);
}

int Solution::numIslands3(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1') {
                _bfs(grid, rows, cols, r, c);
                count++;
            }
        }
    }
    return count;
}

void Solution::_bfs(vector<vector<char>>& grid, int rows, int cols, int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    grid[r][c] = '0';

    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        pair<int, int> curLand = q.front();
        q.pop();
        for (auto& direction: directions) {
            int newr = curLand.first + direction.first;
            int newc = curLand.second + direction.second;
            if (newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                grid[newr][newc] == '0')
                continue;
            grid[newr][newc] = '0';
            q.push({newr, newc});
        }
    }
}
