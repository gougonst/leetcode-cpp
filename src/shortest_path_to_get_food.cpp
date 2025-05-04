#include "shortest_path_to_get_food.h"
#include "queue"

int Solution::getFood(vector<vector<char>>& grid) {
    // Find the '*' location, use BFS from it.
    // Travel to 4 direction of each queue element.
    // There should be a matrix to record the shortest path
    // When updating, if current depth smaller than matrix's value, update it

    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> traveling;
    vector<vector<int>> steps(rows, vector<int>(cols, INT_MAX));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '*') {
                traveling.push({r, c});
                steps[r][c] = 0;
                break;
            }
        }
    }

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int step = 0;
    while (!traveling.empty()) {
        step++;
        int qSize = traveling.size();
        for (int i = 0; i < qSize; i++) {
            pair<int, int> location = traveling.front();
            traveling.pop();
            int r = location.first;
            int c = location.second;
            for (auto& dir: dirs) {
                int newr = r + dir.first;
                int newc = c + dir.second;
                if (newr < 0 || newr >= rows || newc < 0 || newc >= cols)
                    continue;
                if (steps[newr][newc] <= step)
                    continue;
                if (grid[newr][newc] == 'X')
                    continue;
                if (grid[newr][newc] == '#')
                    return step;
                traveling.push({newr, newc});
                steps[newr][newc] = step;
            }
        }
    }
    return -1;
}
