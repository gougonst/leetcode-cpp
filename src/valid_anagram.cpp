#include <unordered_map>
#include "valid_anagram.h"

bool Solution::isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> countBoard;
    for (int i = 0; i < s.length(); i++) {
        countBoard[s[i]]++;
        countBoard[t[i]]--;
    }
    for (const auto& entry: countBoard) {
        if (entry.second != 0) {
            return false;
        }
    }
    return true;
}
