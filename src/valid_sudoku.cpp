#include "valid_sudoku.h"
#include <unordered_set>
#include <unordered_map>

// Brute force: O(n^2)
bool Solution::isValidSudoku1(vector<vector<char>>& board) {
    // Validate row
    for (int r = 0; r < N_ELE; r++) {
        unordered_set<int> validator;
        int numDigits = 0;
        for (int c = 0; c < N_ELE; c++) {
            if (board[r][c] == '.')
                continue;
            validator.insert(board[r][c]);
            numDigits++;
        }
        if (validator.size() != numDigits)
            return false;
    }

    // Validate column
    for (int c = 0; c < N_ELE; c++) {
        unordered_set<int> validator;
        int numDigits = 0;
        for (int r = 0; r < N_ELE; r++) {
            if (board[r][c] == '.')
                continue;
            validator.insert(board[r][c]);
            numDigits++;
        }
        if (validator.size() != numDigits)
            return false;
    }

    // Validate grid
    int interval = sqrt(N_ELE);
    for (int r = 0; r < N_ELE; r += interval) {
        for (int c = 0; c < N_ELE; c += interval) {
            unordered_set<int> validator;
            int numDigits = 0;
            for (int i = r; i < r + interval; i++) {
                for (int j = c; j < c + interval; j++) {
                    if (board[i][j] == '.')
                        continue;
                    validator.insert(board[i][j]);
                    numDigits++;
                }
            }
            if (validator.size() != numDigits)
                return false;
        }
    }

    return true;
}

bool Solution::isValidSudoku2(vector<vector<char>>& board) {
    // Construct a HashMap, {digit: {r, c}}
    unordered_map<int, vector<pair<int, int>>> digitIndices;
    for (int r = 0; r < N_ELE; r++) {
        for (int c = 0; c < N_ELE; c++) {
            char digit = board[r][c];
            if (digit == '.')
                continue;
            digitIndices[digit - '0'].push_back({r, c});
        }
    }

    // For each digit, determine if it is valid in row, col, grid constraints
    for (auto& digitIndex: digitIndices) {
        unordered_set<int> rowConstraint;
        unordered_set<int> colConstraint;
        unordered_set<int> gridConstraint;
        int interval = sqrt(N_ELE);
        for (auto& index: digitIndex.second) {
            int r = index.first;
            int c = index.second;
            rowConstraint.insert(r);
            colConstraint.insert(c);
            gridConstraint.insert((r / interval) * interval + c / interval);
        }
        if (rowConstraint.size() < digitIndex.second.size() ||
            colConstraint.size() < digitIndex.second.size() ||
            gridConstraint.size() < digitIndex.second.size())
            return false;
    }
    return true;
}

bool Solution::isValidSudoku2(vector<vector<char>>& board) {
    // int a[9] = {0, 0, ...}
    // a[0] = bits(000010001)
    // Construct a HashMap, {digit: {r, c}}
    vector<int> rowConstraint(N_ELE, 0);
    vector<int> colConstraint(N_ELE, 0);
    vector<int> gridConstraint(N_ELE, 0);

    for (int r = 0; r < N_ELE; r++) {
        for (int c = 0; c < N_ELE; c++) {
            if (board[r][c] == '.')
                continue;

            int digit = board[r][c] - '1';
            int validateBit = 1 << digit;

            if (rowConstraint[r] & validateBit)
                return false;
            rowConstraint[r] |= validateBit;

            if (colConstraint[c] & validateBit)
                return false;
            colConstraint[c] |= validateBit;

            int interval = sqrt(N_ELE);
            int gridIdx = (r / interval) * interval + c / interval;
            if (gridConstraint[gridIdx] & validateBit)
                return false;
            gridConstraint[gridIdx] |= validateBit;
        }
    }
    return true;
}
