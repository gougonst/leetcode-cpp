#include "rotting_oranges.h"
#include <queue>

int Solution::orangesRotting1(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> rottens;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2)
                rottens.push({r, c});
        }
    }

    int count = 0;
    queue<pair<int, int>> nextRottens;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!rottens.empty() || !nextRottens.empty()) {
        if (!rottens.empty()) {
            pair<int, int> curRotten = rottens.front();
            rottens.pop();
            for (auto &direction: directions) {
                int newr = curRotten.first + direction.first;
                int newc = curRotten.second + direction.second;
                if (newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                    grid[newr][newc] != 1)
                    continue;
                grid[newr][newc] = 2;
                nextRottens.push({newr, newc});
            }
        } else {
            count++;
            swap(rottens, nextRottens);
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1)
                return -1;
        }
    }
    return count;
}

int Solution::orangesRotting2(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int freshCount = 0;
    queue<pair<int, int>> rottens;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2)
                rottens.push({r, c});
            else if (grid[r][c] == 1)
                freshCount++;
        }
    }

    int count = -1;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!rottens.empty()) {
        int curRottenSize = rottens.size();
        while (curRottenSize--) {
            pair<int, int> curRotten = rottens.front();
            rottens.pop();
            for (auto &direction: directions) {
                int newr = curRotten.first + direction.first;
                int newc = curRotten.second + direction.second;
                if (newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                    grid[newr][newc] != 1)
                    continue;
                grid[newr][newc] = 2;
                freshCount--;
                rottens.push({newr, newc});
            }
        }
        if (rottens.size() != 0)
            count++;
    }
    return freshCount > 0 ? -1 : count;
}
