#include <math.h>
#include <unordered_map>
#include "longest_substring_without_repeating_characters.h"

int Solution::lengthOfLongestSubstring(string s) {
    // if incoming character already in the map, repeat.
    // calculate after the charater's index
    // memorize the maximum length of substring
    int maxLength = 0;
    int curLength = 0;
    int dupIdx = 0;
    unordered_map<char, int> idxOfChar;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (idxOfChar.count(c) == 0 || idxOfChar[c] < dupIdx) {
            idxOfChar[c] = i;
            maxLength = max(maxLength, i - dupIdx + 1);
        } else {
            dupIdx = idxOfChar[c] + 1;
            idxOfChar[c] = i;
        }
    }
    return maxLength;
}
