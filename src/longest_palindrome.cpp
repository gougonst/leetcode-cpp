#include <unordered_set>
#include "longest_palindrome.h"

int Solution::longestPalindromeArray(string s) {
    int letterCount[52] = {0};

    for (auto &c: s) {
        int index = (c - 'a') < 0 ? c - 'A' + 26 : c - 'a';
        letterCount[index] += 1;
    }

    int longestLength = 0;
    bool isOddCountHappened = false;
    for (auto &count: letterCount) {
        if (count % 2 == 0) {
            longestLength += count;
        } else if (count > 0) {
            longestLength += count - 1;
            isOddCountHappened = true;
        }
    }
    longestLength = isOddCountHappened ? longestLength + 1 : longestLength;
    return longestLength;
}

int Solution::longestPalindromeSet(string s) {
    int totalLength = 0;
    unordered_set<char> charSet;

    for (auto &c: s) {
        if (charSet.find(c) != charSet.end()) {
            totalLength += 2;
            charSet.erase(c);
        } else {
            charSet.insert(c);
        }
    }

    if (!charSet.empty()) {
        totalLength += 1;
    }
    return totalLength;
}
