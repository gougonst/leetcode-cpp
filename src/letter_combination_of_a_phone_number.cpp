#include "letter_combination_of_a_phone_number.h"
#include <unordered_map>
#include <queue>

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
        return {};

    unordered_map<char, string> mapping;
    mapping['2'] = "abc";
    mapping['3'] = "def";
    mapping['4'] = "ghi";
    mapping['5'] = "jkl";
    mapping['6'] = "mno";
    mapping['7'] = "pqrs";
    mapping['8'] = "tuv";
    mapping['9'] = "wxyz";

    vector<string> combinations;
    string combination = "";
    _buildCombinations(combinations, digits, mapping, combination, 0);
    return combinations;
}

void Solution::_buildCombinations(vector<string>& combinations,
                                  string& digits,
                                  unordered_map<char, string>& mapping,
                                  string combination,
                                  int depth) {
    if (depth == digits.size()) {
        combinations.push_back(combination);
        return;
    }

    for (auto& letter: mapping[digits[depth]]) {
        combination.push_back(letter);
        _buildCombinations(combinations, digits, mapping, combination, depth + 1);
        combination.pop_back();
    }
}
