#include "longest_palindromic_substring.h"

// Brute force
// O(n^3)
string Solution::longestPalindrome(string s) {
    int longestLength = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        for (int j = i - longestLength; j >= 0; j--) {
            string candidate = s.substr(j, i - j + 1);
            if (_isPalindrome(candidate)) {
                longestLength = i - j;
                ans = candidate;
            }
        }
    }
    return ans;
}

bool Solution::_isPalindrome(string s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

// O(n^2)
string Solution::longestPalindrome1(string s) {
    int c = 0;
    int maxLen = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        int len = max(_getPalindromeLen(s, i, i),
                      _getPalindromeLen(s, i, i + 1));
        if (len > maxLen) {
            maxLen = len;
            c = i;
        }
    }
    if (maxLen % 2 == 0)
        return s.substr(c - (maxLen / 2) + 1, maxLen);
    else
        return s.substr(c - maxLen / 2, maxLen);
}

int Solution::_getPalindromeLen(string s, int l, int r) {
    int n = s.length();
    while (l >= 0 && r < n && s[l] == s[r]) {
        l--;
        r++;
    }
    // -2 because l and r will out of the bound
    // abcdce
    //  l   r
    return r - l + 1 - 2;
}
