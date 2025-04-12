#include "word_search.h"
#include <queue>
#include <string>

bool Solution::exist(vector<vector<char>>& board, string word) {
    this->_board = board;
    this->_directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    this->_word = word;
    this->_height = board.size();
    this->_width = board[0].size();
    for (int r = 0; r < this->_height; r++) {
        for (int c = 0; c < this->_width; c++) {
            if (_dfs({r, c}, 0))
                return true;
        }
    }
    return false;
}

bool Solution::_dfs(pair<int, int> loc, int cur) {
    if (cur == this->_word.length())
        return true;
    if (loc.first >= this->_height || loc.first < 0 ||
        loc.second >= this->_width || loc.second < 0 ||
        this->_board[loc.first][loc.second] != _word[cur])
        return false;

    this->_board[loc.first][loc.second] = '#';
    for (auto& direction: this->_directions) {
        int newRow = loc.first + direction.first;
        int newCol = loc.second + direction.second;
        if (_dfs({loc.first + direction.first,
                  loc.second + direction.second}, cur + 1))
            return true;
    }
    this->_board[loc.first][loc.second] = this->_word[cur];
    return false;
}
